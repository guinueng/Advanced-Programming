#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class account{
    long balance;

    public:
    account(long initial_balance = 0) : balance(initial_balance) {}
    //           Can set default value. -> can use nullary constructor.

    void transfer_to(account& ,long amount); // Mutator
    account& operator+=(long amount) { this -> balance += amount; return *this; } // Mutator | It is inside of class, so we can know it is method.
    account& operator-=(long amount) { this -> balance -= amount; return *this; } // Mutator.
    long get_balance() const { return this -> balance; }

    friend std::ostream& operator<<(std::ostream &, account const &); // But can solve as friend. Declaring function and notate as friend. Not a method. It is function!
};

// std::ostream& operator<<(std::ostream &, account const &); // It is function cause it is outside of class.
// ostream class is not account class. So we can't use it as method.
// Generally do not use namespace on .h file.

#endif