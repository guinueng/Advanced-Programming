#include "account.h"
#include <iostream>

using namespace std;

int main(){
    //account a(100000);
    //account a = 100000; // Unary constructor can use equal sign.
    account a, b = 500000; // Nullary constructor or default constructor. ex) balance is 0;
    a += 80000;
    b -= 10000;
    b.transfer_to(a, 50000);

    /*cout << a.get_balance() << endl; // sizeof(a) == sizeof(long)
    cout << b.get_balance() << endl; Assume there is no public getter method. */
    // Call method by using object_name.method() . If () is not used like just a.balance, balance is private property, thus it can't be fetch into outside.
    cout << a << endl; // -> Want to define print out directly.
    cout << b << endl;

    return 0;
}