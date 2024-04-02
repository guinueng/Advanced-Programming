#include <iostream>
#include <cmath>

struct point{
    double x, y; // Due to same type, we can write it in same line.
}; // Don't forget semi-column.

static double Distance(point p1, point p2){
    double x_d = p1.x - p2.x;
    double y_d = p1.y - p2.y;
    return sqrt(x_d * x_d + y_d * y_d); // It is more faster than using pow.
}

int main(){
    using namespace std;

    point ps[2];
    for(int i = 0; i < 2; i++){
        cout << "x for point " << i << ": " << flush;
        cin >> ps[i].x;
        cout << "y for point " << i << ": " << flush;
        cin >> ps[i].y;
    }

    cout << Distance(ps[0], ps[1]) << endl;

    return 0;
}