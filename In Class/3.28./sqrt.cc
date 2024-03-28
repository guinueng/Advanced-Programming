#include <iostream>
#include <cassert>

double square_root(double x, double lower, double upper, int n){
    double const mid = (lower + upper) / 2;
    if(n == 0) return mid;
    double const mid_2 = mid * mid;
    if(mid_2 < x)
        return square_root(x, mid, upper, n - 1);
    else
        return square_root(x, lower, mid, n - 1);
}

double square_root(double x){
    assert(x>=0);
    return square_root(x, 0, x + 1, 50);
}

int main (){
    using namespace std;

    double x;
    cin >> x;
    cout << square_root(x) << endl;

    return 0;
}