#ifndef ACCOUNT_H
#define ACCOUNT_H

class account{
    long balance;

    public:
    account(long initial_balance = 0) : balance(initial_balance) {}
    //           Can set default value. -> can use nullnary constructor.

    void transfer_to(account& ,long amount); // Mutator
    void deposit(long amount) { this -> balance += amount; } // Mutator | It is inside of class, so we can know it is method.
    void withdraw(long amount) { this -> balance -= amount; } // Mutator.
    long get_balance() const { return this -> balance; }

};

#endif