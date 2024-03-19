#include <iostream>

int main (){
    using namespace std;
    
    int x[] = {2, 3, 4, 5};
    cout << x << endl;
    cout << &x[0] << endl; 
    
    /*
    int a = 1, b = 2, c = 3;
    int* d = &a;
    int* e = &b;
    int** f = &d;

    cout << **f << endl;

    *f = &c; // *f = d.
    cout << *d << endl;

    f = &e;
    cout << **f << endl;

    f = (int**)0x1234; // Can put hex, put say to compiler that it is int** type. > Will get SEGV error. | In this course we don't deal w/ this. Maybe on embeded?
    cout << **f << endl;
    */

    /*
    int x = 5;
    cout << x << endl;

    int* y = &x; // 'y' is a pointer to the variable 'x'.
    // Var y is type of pointer of int. = x is var of type int and &x is type of pointer to int.
    // If x is of type pointer to int, *x is type of A. > Dereferencing.

    cout << *y << endl;
    cout << y << endl;

    //cout << &*x << endl; // *x must be pointer type but x is int type. Thus it is illegal.
    cout << *&x << endl; // &x means take pointer of x.

    int z = 7;
    y = &z;
    cout << *y << endl;
    */

    return 0;
}