#include "report.h"
#include <iostream>
#include <fstream> // To use ifstream.

using namespace std;

int main(){
    ifstream fin("a.csv"); // Sub class of istream. f stands for file.
    transaction file_data[1000];
    size_t n;
    for(n = 0; !fin.eof(); n++){
        fin >> file_data[n].transaction_id;
        if(!fin)    break;
        fin.ignore(1, ',');
        fin >> file_data[n].amount;
    }

    cout << "Read in : " << n << "records" << endl;
    plain_text_report r(file_data, n);
    r.write_report(cout);
    
    ofstream html_out("a.html");
    html_report r2(file_data, n);
    r2.write_report(html_out);

    return 0;   
}