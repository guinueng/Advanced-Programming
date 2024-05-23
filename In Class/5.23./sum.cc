#include <iostream>
#include <iomanip>

// Macro style meta programming -> 1. Need to assign needed type. 2. 

template <typename T> // Template -> not defined function yet. Defined potential of function.
T sum(T const* xs, size_t n){
    T total = 0;
    for(size_t i = 0; i < n; i++)
        total += xs[i];
    return total;
}
// 1. template understand c++ syntax definition. Macro does not -> needs in one line. 2. Implicit extency?

using namespace std;
int main(){
    long double const xs[] = {3, 4, 5e9};
    cout << sum(xs, sizeof xs / sizeof xs[0]) << endl;
    short const xs1[] = {3, 4, 5};
    cout << sum<short>(xs1, sizeof xs1 / sizeof xs1[0]) << endl; // <short> we can tell compiler using this types.
    return 0;
}