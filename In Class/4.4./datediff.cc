#include <iostream>
#include <cassert>
using namespace std;

enum class month{jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

static int num_days(month m){
    switch(m){ // Has to indicate what value to switch it. > c++ must be sort of integer or integer-like one.
        // Can use month:: as using namespace month;
        case month::apr:
        case month::jun:
        case month::sep:
        case month::nov:
            return 30;
        case month::feb:
            return 29; // Pretend this year.
        default: // The remain case can expressed as default
            return 31;
    }
}

struct date{
    month m;
    int day;
};

static int day_of_the_year(date const* d){
    int total = 0;
    for(month m = month::jan; m < d->m; m = (month)((int)m + 1)) // (month)((int)m + 1)
        total += num_days(m);
    return total + d-> day;
}

static int day_between(date const* early, date const* late){
    //assert(late->month > early->month || (late->month == early->month && late->day >= early->day) );
    return day_of_the_year(late) - day_of_the_year(early);
}

int main(){
    using namespace std;
    date const d1 = { month::feb, 27 };
    date const d2 = { month::apr, 4 };
    cout << day_between(&d1, &d2) << endl;

    return 0;
}