#include <iostream>
#include "linear_root.h"

using namespace std;

// Not writing prototype of function. If change, we have to change all of them.

int main(){
    int total = 0, passed = 0;
    //     Define macro(values to get) |  What code to write? function, values              '\' used to tall preprocessor next line is also same line.
    #define CHECK(expected_value, arguments)    total++; if(linear_root arguments != expected_value) { \
        cerr << "Linear_root" #arguments << ":got " << linear_root arguments << "; expected " << expected_value << endl; \
        /*fds.*/ \
        } else passed++ // Using macros. cerr to show when error?
        // #arguments '#' is the sign to make stringify it. => "arguments val" | "string1" "string2" > c/c++ will print as "string1string2";
        // When got long list of error, see first one. Below one is caused by first one.
        // Preprocessor error > Good luck.
    
    CHECK(0, (1, 1, 2, 2));
    CHECK(1, (-2, 3, 2, -1));
    CHECK(-0.1, (1, 0, 2, 0.1));
    cout << passed << "/" << total << "test case passed" << endl;
    
    /*
    Using if statement, it would be automated error check. > Annoying!
    if(linear_root(1, 1, 2, 2) != 0)
        cout<<"1 1 2 2 did not work"<<endl;

    cout<< linear_root(1, 1, 2, 2) << endl; // Should be 0.
    cout<< linear_root(-2, 3, 2, -1) << endl; // Should be 1.
    cout<< linear_root(1, 0, 2, 0.1) << endl; // Should be -0.1 .
    */
    return 0;
} 