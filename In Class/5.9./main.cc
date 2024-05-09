#include "shape.h"
#include <iostream>

using namespace std;

double sum_areas(shape const* const* shapes, size_t n){
    double total = 0;
    for(size_t i = 0; i < n; i++)
        total += shapes[i] -> area();
    return total;
}

int main(){
    circle c = 2.0;
    cout << "Area : " << c.area() << endl;

    right_triangle t(3, 4);
    cout << "Area of triangle : " << t.area() << endl;

    shape const* shapes[] = { &c, &t };
    cout << sum_areas(shapes, 2) << endl;

    return 0;
}

/*
#include "array.h"

using namespace std;

int main(){
    array_of_ints a;
    for(size_t i = 0; i < 100; i++)
        a.append(i);
    cout << a << endl;

    array_of_ints b = a; // Using copy constructor which is unary constructor
    cout << b << endl;

    array_of_ints c;
    c = b; // Copying b object to c(not the real value, just copy inside b into c.). Can cause double free problem.
    cout << c << endl;

    return 0;
}
*/