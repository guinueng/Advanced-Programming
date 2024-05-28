#include "parse.h"
#include "expr.h"
#include <iostream>

int main(){
    using namespace std;
    cout << "Enter expression: ";
    expr *e = parse(cin);
    expr *e2 = e -> optimize();
    delete e;
    cout << "f(x) = " << e2 << endl;
    
    
    double x;
    cout << "Enter x to evaluate at: " << flush;
    cin >> x;
    cout << "f(" << x << ") = " << e2 -> eval_at(x) << endl;
    
    expr* derive =  e2 -> derivative();
    expr *derive2 = derive -> optimize();
    delete derive;

    cout << "f'(x) = " << derive2 << endl;
    cout << "f'(" << x << ") = " << derive2 -> eval_at(x) << endl;

    delete e2;
    delete derive2;
    return 0;
}