#ifndef REPORT_H
#define REPORT_H

#include <iostream>
#include <iomanip>

// Do not use using namespace std on .h file.

struct transaction {
    int transaction_id;
    double amount;
};

class report{
    protected: // Can access on this class or child class.
    transaction const* transactions;
    size_t n;
    report(transaction const* ts, size_t n) : transactions(ts), n(n) {}
    public:
    virtual void write_report(std::ostream&) const = 0; // virtual -> child has probability to overwrite that method.
    double total() const;
};

class plain_text_report : public report { // Inherited of parent data representation. -> ex) dont need to implement total method.
    public:
    plain_text_report(transaction const*, size_t); // Constructor does not inherit.
    void write_report(std::ostream&) const override; // override gives signal to overriding parent method.
};

class html_report : public report {
    public:
    html_report(transaction const* ts, size_t n) : report(ts, n) {}
    void write_report(std::ostream&) const override;
};

#endif