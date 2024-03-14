#include <iostream>

int main (){
    using namespace std;
    short xs[] = {-100, 7, -15, 29, 5, 7, 0, 1, 7, 29, 0, 7, -1, -2, 7, 4};
    short max_occurring = xs[0];
    size_t max_occurring_count = 0;
    for(size_t j = 0; j < sizeof xs / sizeof xs[0]; j++){
        size_t count = 0;
        for(size_t i = 0; i < sizeof xs / sizeof xs[0]; i++){
            //count += xs[i] == 7; // This notates count += 0 or 1 when xs[i] == 7 is true or not.
            count += *(xs + i) == xs[j]; // Arr begin would have starting mem add, and offsets. and *() offers mem access.
            // Notation could be xs[i] or *(xs + i).
        }
        if (count > max_occurring_count){
            max_occurring = xs[j];
            max_occurring_count = count;
        }
    }

    cout << "The most commonly occurring element is " << max_occurring << endl;
    return 0;
}