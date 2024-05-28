#ifndef ARRAY_H
#define ARRAY_h

#include <cstddef>

template <typename T>
class array{
    T* elements;
    size_t n;
    public:
    array() : elements(new T[0]), n(0) {} // Using ourselves to not use <>.
    array(array<T> const& other) : elements(new T[other.n]), n(other.n) {
        for (size_t i = 0; i < this -> n; i++)
            this -> elements[i] = other.elements[i];
    } // Referring other object. There has potential which other has diff types. Cause use <T>
    array& operator=(array<T> const& other){
        if(this -> n < other.n){
            delete [] this -> elements;
            this -> elements = new T[other.n];
        }
        this -> n = other.n;
        for(size_t i = 0; i < this -> n; i++)
            this -> elements[i] = other.elements[i];
        return *this;
    }
    ~array() {delete [] this -> elements; }
    T& operator[] (size_t i) const { return this -> elements[i]; }
    array& operator+=(T new_value){
        T* new_elements = new T[this -> n + 1];
        for(size_t i = 0; i < this -> n; i++){
            new_elements[i] = this -> elements[i];
        }
        delete [] this -> elements;
        this -> elements = new_elements;
        this -> elements[this -> n] = new_value;
        this -> n++;
        return *this;
    }
};

// Outside of template use <>.

#endif