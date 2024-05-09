#include "shape.h"
#include <cmath>

double right_triangle::perimeter() const{ // Only write override for class decoration. on h file.
    double hypo = sqrt(this -> length * this -> length * this -> height * this -> height);
    return this -> length + this -> height + hypo;
}