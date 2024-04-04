#include <iostream>
#include <utility> // To use unreachable();
struct number{
    enum class number_type { integer, real } type; // Can define type(function) and it's var name.
    union { // Union does not have name. > it is allowed as anomynous only if it is defined struct.
        long int_value;
        double real_value;
    };
};

number add(number x, number y){
    switch(x.type){
        case number::number_type::integer:
            switch(y.type){
                case number::number_type::integer:
                    return (number){ .type = number::number_type::integer, .int_value = x.int_value + y.int_value };
                case number::number_type::real:
                    return (number){ .type = number::number_type::real, .real_value = x.int_value + y.real_value};
            }
        case number::number_type::real:
            switch(y.type){
                case number::number_type::integer:
                    return (number){ .type = number::number_type::real, .real_value = x.real_value + y.int_value };
                case number::number_type::real:
                    return (number){ .type = number::number_type::real, .real_value = x.real_value + y.real_value };
            }
    }
    __builtin_unreachable();
}

int main(){
    using namespace std;

    number a = { .type = number::number_type::integer, .int_value = 3};
    number b = { .type = number::number_type::real, .real_value = 6.5};
    cout << add(a, b).real_value << endl;

    return 0;
}