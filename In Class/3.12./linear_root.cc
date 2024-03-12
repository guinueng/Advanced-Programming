#include <cassert>
// Using Assertion function. > To assume it is true.
#include "linear_root.h" // Makes no difference. But including due to habbit.

double linear_root(double x1, double y1, double x2, double y2){
    /*
      At what y value does the line described by the two points (x1, y1) and (x2, y2) cross the y-axis?
      Assume that x1 != x2.
    */
    assert(x1 != x2); // Assume it is true. If it is true happens nothing. But false, it prints fail error.
    double m = (y1 - y2) / (x1 - x2);

    return y1 - m * x1;
}