#include <iostream>
#include <climits> // To use SSIZE_MAX

using namespace std;

int main(){
    double num;
    bool got_good_input = false; // Also int type.

    while(!got_good_input){ // do while > nope! due to we have to use cin.clear and ignore func.
        cout << "Please enter a number : " << flush;
        cin >> num;
        if (cin)
            got_good_input = true;
        else{
            cin.clear(); // Cin is now good state;
            cin.ignore(SSIZE_MAX, '\n'); // clear the buffer of the current line of text;
            /*cout << "Please enter a number : " << flush;
            cin >> num;
            cout << "You entered the number " << num << endl;
            cout << "Try again" << endl;
            main(); // Brilliant?! But not work forever.
            By using yes func, it crashed!
            Terminated due to call stack. OS gives fixed size of call stack.*/
        }
    }
    
    return 0;
}

// Unix code yes. > put infinite # of y.