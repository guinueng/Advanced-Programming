#include "parse.h"
#include "expr.h"
#include <iostream>

int main(){
    using namespace std;
    cout << "Enter expression: ";
    expr *e = parse(cin);
   // expr *e2 = e -> optimize();
    //delete e;
    cout << "f(x) = " << e << endl;
    
    
    double x;
    cout << "Enter x to evaluate at: " << flush;
    cin >> x;
    cout << "f(" << x << ") = " << e -> eval_at(x) << endl;
    
    //expr* deriv =  e2 -> derivative();
    //expr *derive2 = derive -> optimize();
    expr* deriv =  e -> derivative();
    //delete deriv;

    cout << "f'(x) = " << deriv << endl;
    cout << "f'(" << x << ") = " << deriv -> eval_at(x) << endl;
    //delete drive2;
    delete e;
    delete deriv;
    //delete e2;

    return 0;
}