#include "account.h"

void account::transfer_to(account& other,long amount){
    this -> balance -= amount; // this is ptr but other is reference. Thus, it does not need dereference. -> == deference + '.' .
    other.balance += amount; // Writing code in account class, thus we can fetch private properties.
}

using namespace std;
ostream& operator<<(ostream& out, account const &a){
    return out << "Bank account with balance : "
                << a.balance;
}