#include "report.h"

using namespace std;

plain_text_report::plain_text_report(transaction const* ts, size_t n)
    : report(ts, n) {}

double report::total() const{
    double t = 0;
    for(size_t i = 0; i < this -> n; i++)
        t += this -> transactions[i].amount;
    return t;
}

void plain_text_report::write_report(ostream& out) const{
/*
 *  Example report :
 *  | Transaction ID |   Amount |
 *  |----------------+----------|
 *  |              1 |   57.230 |
 *  |              2 |   40.000 |
 * 
 *  Total :              08.230
 */
    out << "| Transaction ID |   Amount |\n";
    out << "|----------------+----------|\n";
    for(size_t i = 0; i < this -> n; i++)
        out << setw(16) << this -> transactions[i].transaction_id
            << " |" << fixed << setw(9) << setprecision(3)
            << this -> transactions[i].amount <<" |\n";
    out << "\nTotal:" << setw(21) << this -> total() << "\n";

}

void html_report::write_report(ostream& out) const{
    out << "<table>";
    out << "<thead><th>Transaction ID</th><th>Amount</th></thead>";
    out << "<tbody>";
    for(size_t i = 0; i < this -> n; i++)
        out << "<tr><td>" << this -> transactions[i].transaction_id
            << "</td><td>" << setprecision(3)
            << this -> transactions[i].amount << "</td></tr>";
    out << "</tbody>";
    out << "</table>";
    out << "<p>Total: " << this -> total() << "</p>";
}