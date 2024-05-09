#ifndef SHAPE_H
#define SHAPE_H
#include <cmath>

class shape{ // Abstract class.
    public:
    virtual double area() const = 0; // virtual means this function can be overwritten. "= 0;" only used on virtual, which means this function is abstract -> declare possibility that other class can make.
    virtual double perimeter() const = 0; // =0 means abstract. this does not exist. -> entire class becomes abstract. -> don't have implementation of function.
};

class right_triangle : public shape{ //Concrete class. : public involves on inheritance. ":" notates is_a relationship. -> triangle must make function on shape.
    double length, height;
    public:
    right_triangle(double l, double h) : length(l), height(h) {}
    double area() const override { return this -> length * this -> height / 2; } // If we give implementation on parent class, write override. Forgor does not matter.
    double perimeter() const override;
};

class circle : public shape{
    double radius;
    public:
    circle(double r) : radius(r) {}
    double area() const override { return M_PI * this -> radius * this -> radius; }
    double perimeter() const override { return 2 * M_PI * this -> radius ;}
};

#endif