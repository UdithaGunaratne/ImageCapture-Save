#include <fstream>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
using namespace std;

bool dirValidator(string);
string dirFromTheFile(string);
bool extenChecker(string, string);

int imgCoppy(string srcFile, string trgFile){

    if(!dirValidator( dirFromTheFile( srcFile ) ) ){
        cerr << "Source Folder Does Not Exist !!" << endl;
        return 0;
    }

    if(!dirValidator( dirFromTheFile( trgFile ) ) ){
        cerr << "Target Folder Does Not Exist !!" << endl;
        return 0;
    }

    if(!extenChecker(srcFile, trgFile)){
        cerr << "Extention of Source File does Not Match to Trget File's !!!!!" << endl;
        return 0;
    }

    ifstream srcImg(srcFile.c_str(), ios::binary);
    if(!srcImg){
        cerr << "Source Image Does Not Exist !!" << endl;
        return 0;
    }


    ofstream trgImg(trgFile.c_str(), ios::binary);

    copy(istreambuf_iterator<char>(srcImg), istreambuf_iterator<char>(), ostreambuf_iterator<char>(trgImg));

    return 1;
}

bool dirValidator(string dir){
    struct stat info;

    if      ( stat( dir.c_str(), &info ) != 0)      return false;
    else if ( info.st_mode & S_IFDIR )              return true;
    else                                            return false;

}

string dirFromTheFile(string file){

    string dir;

    if ( count(dir.begin(), dir.end(), '/') == 1)   return dir;
    else if(file.find('/') != string::npos){
        dir = file.substr(0, file.find_last_of('/'));
        return dir;
    }
    else    return "./";

}

bool extenChecker(string srcFile, string trgFile){
    int posSrc = srcFile.find_last_of('.');
    int posTrg = trgFile.find_last_of('.');
    if( srcFile.substr( posSrc+1 ) == trgFile.substr( posTrg + 1)) return true;
    else return false;

}
