#include <iostream>
#include <cmath>
#include <climits>

int main(){
    using namespace std;
    short x;
    cin >> x;

    short abs_x = x == SHRT_MIN ? SHRT_MAX : abs(x); // It is equivalent to below one.
    /*
    if(x == SHRT_MIN) // If -32868(?) case, it would cause undefined behavior.
        abs_x = SHRT_MAX; // Cause have to return SHRT_MAX val.
    else
        abs_x = abs(x);
    */
    cout << abs_x << endl;
    
    return 0;
}