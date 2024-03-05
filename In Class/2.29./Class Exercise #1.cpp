#include <iostream>
using namespace std;

int num_divisors (long n){
    int count = 0; // Return val must be same as function's type.
    for(long i = 1; i <= n; i++){ // Using long due to related to input # n.
        if(n % i == 0)
            count++;
    }
    return count;
}

int main(){
    cout<<"Please Enter the Number : "<< flush; //Why using flush is it indicated print out directly. 
    // Print needs system help -> system call. It is slow.
    // Thus, C++ does not print directly, keeps in buffer.
    long n;
    cin>>n;
    for(long i = 1; i <= n; i++){
        cout<<i<<"\t"<<num_divisors(i)<<endl; // Tab stop makes automatically blanks within the values.
    }

    return 0;
}

// g++
// Name of Compiler 
// -Wall > turn on warning
// -std=? saying ver of prog.
// -g put debug func(?)
// -o output which create.
// Last one is name of source file. .cc/cpp/cxx ect...