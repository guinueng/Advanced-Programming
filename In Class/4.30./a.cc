#include <iostream>

using namespace std;

long* factor(long x, size_t& n){
    /*
        Return the prime factors of x, as an array on the heap.
        'n' is reference to a size_t which will be populated w/ the # of element in the array.
    */

    long* fs = new long[x];
    n = 0;
    for(long i = 2; i <= x; i++){
        while(x % i == 0){
            fs[n] = i;
            x /= i;
            n++;
        }
    }

    return fs;
}

int main(){
    size_t n;
    long x;
    cout << "Enter a number : " << flush;
    cin >> x;
    long* fs = factor(x, n);
    for(size_t i = 0; i < n; i++)
        cout << fs[i] << " ";
    cout << endl;
    delete [] fs; // If allocated array, use [] front.
    return 0;
}