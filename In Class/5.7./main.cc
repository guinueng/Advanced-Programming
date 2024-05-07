#include "array.h"

using namespace std;

int main(){
    array_of_ints a;
    cout << a << endl;
    a.append(3);
    cout << a << endl;
    a.append(4);
    cout << a << endl;
    a.append(5);
    cout << a << endl;
    a.remove(1);
    cout << a << endl;

    array_of_ints b = a;
    cout << b << endl;

    return 0;
}