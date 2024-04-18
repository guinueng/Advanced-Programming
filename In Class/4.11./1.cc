#include <iostream>
#include <cmath>
#include <utility>

struct shape{
    enum class shape_type{ circles, rectangles } type;
    union{
        double radius;
        struct{
            double length, width;
        } rectangle;
    };
};

double area(shape s){
    switch(s.type){
        case shape::shape_type::circles:
            return M_PI * s.radius * s.radius;
            break;
        case shape::shape_type::rectangles:
            return s.rectangle.width * s.rectangle.length;
    }
    __builtin_unreachable();
}

double avg_area(shape const* s, size_t n){
    double total = 0;
    for(size_t i = 0; i < n; i++){
        total += area(s[i]);
    }

    return total / n;
}

int main (){
    using namespace std;

    shape arr[4] = {
        #define CIRC(r) { .type = shape::shape_type::circles, .radius = r }
        #define RECT(x, y)  { .type = shape::shape_type::rectangles, .rectangle = {x, y} }
        CIRC(1), CIRC(0.5), RECT(2.5, 14), RECT(5, 5)
    };
    
    cout << avg_area( arr, 2 ) << endl;

    cout << avg_area( arr + 2, 2 ) << endl;

    cout << avg_area( arr, sizeof(arr) / sizeof(arr[0]) ) << endl;

    return 0;
}