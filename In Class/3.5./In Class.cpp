#include <iostream>
long fact(long); //> Function prototype. Inform compiler this function exist somewhere.
//#define X 1 + 1
//#define until(cond) while(!(cond))
//Preprocessor understand pherenblabla.

int main(){
    /*int ans = 1;
    int i = 10;
    until (i == 0){ // > loop
        ans *= i;
        i--;
    }*/
    std::cout<<fact(9)<<std::endl;
    return 0;
    //return X * X;
}//Not using #incl.... to be simple file.
// g++ -E "file name" > preprocess c++.
// Preprocessor doesn't understand c++.
// Only knows cpy and paste.
// If we define x 1 + 1 and return x*x > preprocess will return 1 + 1 * 1 + 1 = 3.
// g++ -S "File name" > creates .s file which is assembly file.
// linker error contains 'ld' reference.
// CXXFLAGS = use this when you compile it. = | += >if exist cxxflags ow or add? Does not effect on class.
// Exe name: Tab(no spacebar) target .o file
// g++ -o $@ $^
//        name of 1st target name, 2nd name 
// make > TA will type.
// Modified