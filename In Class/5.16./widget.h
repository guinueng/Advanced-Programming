#ifndef WIDGET_H
#define WIDGET_H

#include <string>

typedef unsigned int uint; // typedef defines new name of type.

class widget{
    public:
    virtual char char_at(uint x, uint y, uint width, uint height) const = 0; // Did not declared abstract, compiler confused this function exist.
    virtual ~widget() {} // If vtable contained element deleted, parent class needs virtual destructor.
};

class label : public widget{ // label just displays text.
    std::string text;
    public:
    label(std::string t) : text(t) {}
    char char_at(uint, uint, uint, uint) const override;
};

class checkerboard : public widget{
    char a, b;
    public:
    checkerboard(char a, char b) : a(a), b(b) {}
    char char_at(uint, uint, uint, uint) const override;
};

class stretchy : public widget{
    public:
    stretchy() {}
    char char_at(uint, uint, uint, uint) const override;
};

class two_widget_container : public widget{ // Contains some widgets. Abstract.
    widget* first, * second;
    public:
    // FIX IT on MON.
    two_widget_container() {}
    ~two_widget_container() { delete this -> first; delete this -> second; }
};

class vertical_split : public two_widget_container{
    widget* top, * bottom; // If you want to decl ptr in same line, add * at that elem.
    public:
    vertical_split(widget* t, widget* b) : two_widget_container(t, b) {}//top(t), bottom(b) {} // Due to rule of 3, we need signed operator.
    char char_at(uint, uint, uint, uint) const override;
    //~vertical_split() { delete this -> top; delete this -> bottom; }
};



#endif