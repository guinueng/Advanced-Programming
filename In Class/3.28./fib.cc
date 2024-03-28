#include <iostream>

void fib(long long* fibs, size_t n, long long i = 0){ // Can set default values in parameter.
    if(n == 0)
        return;
    if(i <= 1)  *fibs = i;
    else        *fibs = fibs[-1] + fibs[-2];
    fib(fibs + 1, n - 1, i + 1);
}
/*
    void fib(long long* fibs, size_t n, long long i = 0){} is same as
    void fib(long long* fibs, size_t n){
        fib(fibs, n, 0);
    }
*/

int main(){
    using namespace std;
    long long fibs[4];
    fib(fibs, sizeof fibs / sizeof fibs[0]);
    for(size_t i = 0; i < sizeof fibs / sizeof fibs[0]; i++)
        cout << fibs[i] << "\n";
    return 0;
}