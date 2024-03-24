#include <iostream>
#include <cassert>

using namespace std;

size_t factors(unsigned long n, unsigned long* fs, size_t max_fs){
    assert(max_fs > 0);
    size_t factor_i = 0;
    for (unsigned long i = 2; i <= n;){
        if(n % i == 0){
            if(factor_i == (max_fs)){
                fs[factor_i] = n;
                return max_fs;
            }
            else
                fs[factor_i] = i;
            factor_i++;
            n /= i; // If forgot, gets infinite error.
        }
        else
            i++;
    }

    return factor_i; // Returns real size.
}

int main(){
    unsigned long x;
    cout << "Enter number to factor: " << flush;
    cin >> x;
    unsigned long fs[10]; // Hardcode some big number.
    size_t num_fs = factors(x, fs, sizeof(fs) / sizeof(fs[0]));
    for(size_t i = 0; i < num_fs; i++){
        cout << fs[i] << endl;
    }
    return 0;
}

/*
    To use debugger, rm add sanitizer.
    By using #.
    use gdb.
    Reading symbols from ~~ should be correctly loaded status.
    if enter start, it begins.
    if want to go next statement, type next or n.
    If first entered, you can just press enter.
    start > Automatically breaks.
    p -> print option. which I inputted.
    ex) p x -> print x value.
    s (step) -> I want to step in function. and call it.
    quit as q.
    set breakpoint as b source file:line#
    backtrace(bt) print out call stacks.
    up -> goes call stack downwards.
*/