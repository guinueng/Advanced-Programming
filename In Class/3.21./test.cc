#include <iostream>

long f(long a, double b, short* c){
    return a;
}

int main (){
    using namespace std;

    short xs[] = {-100, 7, -15, 29, 5, 7, 0, 1, 7, 29, 0, 7, -1, -2, 7, 4};
    long y = 12;
    double z = 3.5;
    cout << f(y, z, &xs[2]) << endl;

    /*
    //short* y = &xs[2];
    //*y += 2;
    //cout << y[1] << endl; // Due to y += 2; it points 7. Due to *y += 2, it changes contained value. Thus print result would be 29.
    //cout << y[-1] << endl; should be 7 due to y points -15.
    */

    /*
    cout << xs << "\n"
        << &xs[0] << "\n"
        << xs + 1 << "\n"
        << &xs[1] << "\n"
        << xs + 2 << "\n"
        << &xs[2] << endl;
    cout << 0[xs] << endl; // C++'s addition is communitive.
    */
    return 0;
}

// xs[i] == **(xs + i) and && xs[i] == xs + i
// Typecase > ex) int** y = (int **)0x1234.
// (int **) is typecase. Which conv val into given type. > Interpret it!
// Pointer arithmetic is valid for only +. > Should be cautious. | It is automatically adding size of index.
