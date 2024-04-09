#include <iostream>
#include <utility> // To use unreachable();
struct number{
    enum class number_type { integer, real, rational } type; // Can define type(function) and it's var name.
    union { // Union does not have name. > it is allowed as anonymous only if it is defined struct.
        long int_value;
        double real_value;
        struct {
            int numer;
            unsigned denom;
        } fraction;
    }; // Union base polymorphism may have some limitations for extending. Use when there's no extend. -> It can solve as inheritance polymorphism.
};

// Polymorphic function -> parameter can have variety types. Polymorphism -> Variety.
number operator+(number x, number y){ // Overload operator func. (Use as operator'Want to overload') (x, y) matches x as left value and y as right value.
    switch(x.type){
        case number::number_type::integer:
            switch(y.type){
                case number::number_type::integer:
                    return (number){ .type = number::number_type::integer, .int_value = x.int_value + y.int_value };
                case number::number_type::real:
                    return (number){ .type = number::number_type::real, .real_value = x.int_value + y.real_value };
                case number::number_type::rational:
                    return (number){ .type = number::number_type::rational,
                        .fraction = { .numer = (int)(y.fraction.numer + y.fraction.denom * x.int_value) , .denom = y.fraction.denom } };
            }
        case number::number_type::real:
            switch(y.type){
                case number::number_type::integer:
                    return (number){ .type = number::number_type::real, .real_value = x.real_value + y.int_value };
                case number::number_type::real:
                    return (number){ .type = number::number_type::real, .real_value = x.real_value + y.real_value };
                case number::number_type::rational:
                    return (number){ .type = number::number_type::rational, .real_value = x.real_value + y.fraction.numer / (double) y.fraction.denom };
                        // int / int => int. We want to get real number. Thus forced by using (double).
            }
        case number::number_type::rational:
            switch(y.type){
                case number::number_type::rational:
                    return (number){ .type = number::number_type::rational,
                        .fraction = { .numer = (int)(x.fraction.numer * y.fraction.denom + y.fraction.numer * x.fraction.denom), .denom = x.fraction.denom + y.fraction.denom } };
                default: y + x; // Recursive function.
            }
    }
    __builtin_unreachable();
}

void operator+=(number& left, number const& right){
    left = left + right;
}

using namespace std;

ostream& operator<<(ostream& out, number n){ // Ostream stand for output stream. Need ostream pointer due to mod it.
    switch(n.type){
        case number::number_type::integer:
            out << n.int_value; // Normally, exec all below statement in switch case usage (fall trough behavior).
            break; // Thus if don't want to fall down, use break. ('60s).
        case number::number_type::real:
            out << n.real_value;
            break;
        case number::number_type::rational:
            out << n.fraction.numer << "/" << n.fraction.denom;
    }

    return out;
}

number sum(number const* nums, size_t num_nums){
    number total = { .type = number::number_type::integer, .int_value = 0 };
    for(size_t i = 0; i < num_nums; i++)
        total += nums[i];

    return total;
}

int main(){ // If using reference &, when using it always dereference it and it is implicit.
    number a = { .type = number::number_type::integer, .int_value = 3};
    number b = { .type = number::number_type::rational, .fraction = { 9, 7 } };
    #define F(x)    { .type = number::number_type::real, .real_value = x }
    number const xs[] = { F(3), F(9.5), F(-10), F(27) };
    cout << (a + b) << endl;
    cout << sum(xs, (sizeof(xs) / sizeof(xs[0])) ) << endl;

    return 0;
}