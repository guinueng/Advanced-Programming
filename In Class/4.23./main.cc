#include "account.h"
#include <iostream>

using namespace std;

int main(){
    //account a(100000);
    account a = 100000; // Unary constructor can use equal sign.
    account b; // Nullnary constructor or default constructor. ex) balance is 0;
    cout << a.get_balance() << endl;
    // Call method by using object_name.method() . If () is not used like just a.balance, balance is private property, thus it can't be fetch into outside.

    return 0;
}