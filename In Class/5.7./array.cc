#include "array.h"

array_of_ints::array_of_ints(array_of_ints const& other) : data(new int[other.n]), n(other.n){
    for(size_t i = 0; i < this -> n; i++)
        this -> data[i] = other.data[i];
}

void array_of_ints::append(int new_int){
    int* new_array = new int[this -> n + 1];
    for(size_t i = 0; i < this -> n; i++)
        new_array[i] = this -> data[i];

    new_array[this -> n] = new_int;
    delete [] this -> data;
    this -> data = new_array;
    this -> n++;
}

void array_of_ints::remove(size_t i){
    for(size_t j = i + 1; j < this -> n; j++)
        this -> data[j - 1] = this -> data[j];
    this -> n--;
}

using namespace std;

ostream& operator<<(ostream& out, array_of_ints const& a){
    out << "[";
    for(size_t i = 0; i + 1 < a.length(); i++){
        out << a[i] << ", ";
    }
    if(a.length())
        out << a[a.length() - 1];
    return out << "]";
}