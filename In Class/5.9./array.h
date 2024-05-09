#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class array_of_ints{
    int* data;
    size_t n;

    public:
    array_of_ints() : data(new int[0]), n(0) {}; // Default Constructor.(nullary) on data we can use new int[0] -> gives pointer(book keeping) but it's length is 0 thus we can't do anything. or nullptr. But nullptr can cause some error.
    array_of_ints(array_of_ints const& other); // Copy constructor. (unary constructor)
    void append(int);
    void remove(size_t);
    size_t length() const { return this -> n; }
    int& operator[](size_t i) const { return this -> data[i]; } // Referencing operator is implicit.
    array_of_ints& operator=(array_of_ints const&);
    ~array_of_ints() { delete [] this -> data; } // Destructor

    /*
     *  Rule of 3.
     *  If you have only one of those 3 (destructor, constructor, copy constructor), you probably need the whole of them.
     */
};

std::ostream& operator<<(std::ostream&, array_of_ints const&);


#endif