#include <iostream>

static double sum(double const* xs, size_t n){
    double total = 0;
    for(size_t i = 0; i < n; i++)
        total += xs[i];
    return total;
}

int main (){
    using namespace std;
    /*int xs[] = {1, 2, 3};
    int ys[] = {9, 10, 11};
    int const* const z = xs; // const z > Can't update. can't be changed. int const > I cannot use to modify what i am pointing.
    cout << *z << endl;*/
    double xs[] = {2, 3, 9.5, -1e-2};
    cout << sum(xs, sizeof xs / sizeof xs[0]) << endl;
    return 0;
}