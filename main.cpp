#include <iostream>
#include "flags.hpp"
#include "capImg.hpp"
#include <thread>
#include <stdio.h>
#include "imgCoppier.hpp"
#include <filesystem>

int main(){

    char c;
    int index;
    std::string defect, image_id, srcPath_to_defect, trgPath_to_defect;

    char inputs[9] = { '0','1', '2', '3', '4', '5', '6', '7', '8'};
    //defects should be the set for needed defects, NOTE: Releven Directories must be created maually.
    std::string defects[9] = { "hello", "what", "is", "happening", "my", "best", "freind", "in", "the"};

    init_release_cpp_flag(); //intial release of the image capture using python thread

    std::thread capImg(captureImage);

    system("stty raw");
    while(1){
        c = getchar();

        if( c == 'e'){
            set_cpp_flag();
            system("stty cooked");
            while(py_flag() != 0){}
            exit(0);
        }

        char* found = std::find(std::begin(inputs), std::end(inputs), c);

        if( found != std::end(inputs)){
            index = std::distance(inputs, found);
            defect = defects[index];
            system("stty cooked");

            set_cpp_flag(); //This is to lock the image capture using python thread.

            while(py_flag() != 0){} //This is for waiting till image capture using python thread complets his work and release the thread
            
            //copy the file
            image_id = saved_images();
            trgPath_to_defect = "./defects/" + defect + "/" + image_id + ".jpg";
            srcPath_to_defect = "./images/" + image_id + ".jpg";
            imgCoppy(srcPath_to_defect, trgPath_to_defect);
            //copy the file
            
            release_cpp_flag(); //This is to release the image capture using python thread.

            system("stty raw");
        }
    }

    capImg.join();    

    return 0;
}