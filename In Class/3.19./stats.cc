#include <iostream>
#include <cmath> // To use pow or sqrt func, we have to include <cmath>.
/*
 * Read in some numbers (max 100). Calc their mean and Standard Deviation and print it out.
 */
// yes 500 | ./stats > input 500 yes on stats exe.


int main(){
    using namespace std;
    // arrays would be a fixed size.
    double numbers[100];
    size_t n;
    cout << "How many numbers to read in? " << flush;
    cin>>n;

    if(n > sizeof numbers / sizeof numbers[0]){
        cerr << "n is too big" << endl; // By using cerr we can print thing just error case.
        return 1;
    }

    for(size_t i = 0; i < n; i++){
        cin >> numbers[i];
    }

    double sum = 0;
    for(size_t i = 0; i < n; i++){
        sum += numbers[i];
    }

    double mean = sum / n;
    cout << "Mean : " << mean << endl;

    double variance = 0;
    for(size_t i = 0; i < n; i++){
        double diff = numbers[i] - mean;
        variance += diff * diff;
    }

    cout << "Standard Deviation : " << sqrt(variance / n) << endl;

    return 0;
}