#include "array.h"
#include <iostream>

using namespace std;

int main(){
    array<double> xs;
    xs += 3.5;
    array<char> ys;
    ys += 'h';
    array<double> zs = xs;
    xs += 5;
    return 0;
}