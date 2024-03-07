#include <iostream>
#include <cmath>
#include <iomanip> // Use to use setprecision.

using namespace std;

int main(){
    cout <<"Square roots up to what number? "<<flush; // Use flush to print before input.
    long n; cin>>n;

    for(long i = 0; i <= n; i++)
        cout << setw(3) << i << "\t" << fixed << setprecision(8) << setw(12) << sqrt(i) << "\n";
        // Two type of printing float. By fixed(1.125599) or scientific notation. There has automatic mode to choose is in cout.
        // fixed will notice cout I will use only fixed.
        // cout<<i<<"\t"<<sqrt(i)<<"\n"; // "\t" is tab line. using \n is tiny efficient. > Complete print and flush is efficient.
        // Want to print more digit.
        // Want to consistency of digit.
        // cout automatically left line. > how to right line? Set the width by setw().
        // setw() does not change automatically. So if you want to be diff width, set each!
        // Should use on Assignment 1.
    cout<<flush; // Flush is out of for loop.

    return 0;
}