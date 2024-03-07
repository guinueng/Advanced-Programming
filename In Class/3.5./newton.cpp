#include <iostream>
#include <cmath>
using namespace std;

double evaluate_cubic(double a, double b, double c, double d, double x){
    return a*x*x*x + b*x*x + c*x + d;
}

double evaluate_quadratic(double a, double b, double c, double x){
    return a*x*x + b*x + c;
}

double root_of_cubic(double a, double b, double c, double d){
    // f(x) = ax**3 + bx**2 + cx + d
    double d_a = 3 * a, d_b = 2 * b, d_c = c;
    double x = 7; // Init guess for x_0.
    double old_x; // Use this to find diff between x and old x. < del init val 8.
    do{
        old_x = x;
        x = x - evaluate_cubic(a, b, c, d, x) / evaluate_quadratic(d_a, d_b, d_c, x);
    }while(fabs(x - old_x) >= 0.001); // > Changed do while loop. > In machine code it is more efficient.
    // Need iteration to get 1st val of old_x.
    return x;
}

int main(){ // Defined as entry point.
    cout<< root_of_cubic(1, -2, -11, 12) <<endl;
   return 0;
}