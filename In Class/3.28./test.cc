#include <iostream>
#include <climits> // Use to get max_size of size_t
using namespace std;

char const* search(char const* xs, size_t n, char c){ // Using const due to no mod in arr.
    for(size_t i = 0; i < n; i++)
        if(xs[i] == c)
            return xs + i;

    return nullptr; // c/c++ defined special pointer which does not matches into specific pointers.
}

size_t intersect(char const* xs, size_t x_n, char const* ys, size_t y_n, char* out){ // To return size of two char arr.
    /*
        note 'out' must point to an array of size equal to or greater than the smaller of x_n, y_n.
    */
    size_t out_i = 0;
    for(size_t x_i = 0; x_i < x_n; x_i++)
        if(search(ys, y_n, xs[x_i])){
            out[out_i] = xs[x_i];
            out_i++;
        }
    
    return out_i;
}


int main(){
    //char const xs[] = {3, 9, 7, 'A', 44}; // Distinction exist between '' => one character "" > arrays.
    char const xs[] = "hello there!";
    char const ys[] = {9, 17, 'h', 'o', 12, 'r', '!'};
    char common[15];
    size_t common_n = intersect(xs, sizeof xs, ys, sizeof ys, common); // did not div sizeof xs[0] cause sizeof char = 1.
    for(size_t i = 0; i < common_n; i++)
        cout << (int)common[i] << " ";
    cout<<endl;

    /*
    char const* location = search(xs, sizeof xs / sizeof xs[0], 7);
    if (location)
        cout << "found it: " << location - xs << endl;
    else
        cout << "did not find it" << endl;
    
    location = search(xs, sizeof xs / sizeof xs[0], 'B');
    if (location)
        cout << "found it: " << location - xs << endl;
    else
        cout << "did not find it" << endl;
    */

    return 0;
}