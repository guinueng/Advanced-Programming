#include "parse.h"
#include "expr.h"
#include <iostream>

int main(){
    using namespace std;
    cout << "Enter expression: ";
    expr *e = parse(cin);
    cout << "1 f(x) = " << e << endl;
    expr *e2 = e -> optimize();
    cout << "2 f(x) = " << e2 << endl;
    delete e;
    expr *e3 = e2 -> optimize();
    delete e2;
    cout << "f(x) = " << e3 << endl;
    
    double x;
    cout << "Enter x to evaluate at: " << flush;
    cin >> x;
    cout << "f(" << x << ") = " << e3 -> eval_at(x) << endl;
    
    expr* derive = e3 -> derivative();
    expr* derive2 = derive -> optimize();
    delete derive;
    expr* derive3 = derive2 -> optimize();
    delete derive2;
    cout << "f'(x) = " << derive3 << endl;
    cout << "f'(" << x << ") = " << derive3 -> eval_at(x) << endl;

    delete e3;
    delete derive3;
    return 0;
}