#include<fstream>
#include<iostream>

void set_cpp_flag(){
    std::ofstream w_file;
    w_file.open("./cpp_flag.txt", std::ios::in);
    w_file << 1;
    w_file.close();
}

void release_cpp_flag(){
    std::ofstream w_file;
    w_file.open("./cpp_flag.txt", std::ios::in);
    w_file << 0;
    w_file.close();
}

void init_release_cpp_flag(){
    std::ofstream w_file;
    w_file.open("./cpp_flag.txt");
    w_file << 0;
    w_file.close();
}

std::string saved_images(){
    int index = 0;
    std::ifstream r_file;
    std::string text;
    std::string texts[9];
    r_file.open("./saved_images.txt");
    while( getline(r_file, text)){
        texts[index] = text;
        // std::cout << text << std::endl;
        index++;
    }
    int out = index/2;

    return texts[out];
}

int py_flag(){
    char c;
    std::ifstream r_file;
    r_file.open("./py_flag.txt");
    r_file >> c;
    r_file.close();
    
    if ( c == '0') return 0;
    else if ( c == '1') return 1;
    else return -1;
}
