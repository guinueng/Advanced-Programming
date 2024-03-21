#include <iostream>
#include <numeric> // To use internal GCD function.

/*
void reduce_fraction(int* numer, int* denom){
    int fraction_gcd = std::gcd(*numer, *denom);
    *numer /= fraction_gcd;
    *denom /= fraction_gcd;
}
*/

int sum(int const* x, size_t size){ // size_t is used for notate index or size.
    int total = 0;
    for(size_t i = 0; i < size; i++)
        total += x[i];
    //x[0] = 10; // > Compiler will terminate it.
    return total;
}

int main (){
    using namespace std;
    int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << sum(x + 2, 5) << endl;
    cout << sizeof(x) << endl; // x does not decayed thus it's size is 40.
    cout << sizeof(x + 0) << endl; // Arrays decayed into pointers due to '+ 0' thus it's size is 8.
    
    /*
    int* y = x;

    cout << sizeof x / sizeof x[0] << endl;
    cout << sizeof y / sizeof y[0] << endl; // sizeof y[0] == sizeof x[0], sizeof y = depends on machine. In 64bits system, size of pointer would be 8bytes.

    //int numer = 24, denom = 60;
    //reduce_fraction(&numer, &denom);
    //cout << numer << "/" << denom << endl;
    */
    return 0;
}
// C++ prohibits multiple return values.