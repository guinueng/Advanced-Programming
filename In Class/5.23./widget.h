#ifndef WIDGET_H
#define WIDGET_H

#include <string>

typedef unsigned int uint; // typedef defines new name of type.

class widget{
    public:
    virtual char char_at(uint x, uint y, uint width, uint height) const = 0; // Did not declared abstract, compiler confused this function exist.
    virtual widget* copy() const = 0; // Force to have it.
    virtual ~widget() {} // If vtable contained element deleted, parent class needs virtual destructor.
};

class label : public widget{ // label just displays text.
    std::string text;
    public:
    label(std::string t) : text(t) {}
    char char_at(uint, uint, uint, uint) const override;
    widget* copy() const override { return new label(this -> text); };
};

class checkerboard : public widget{
    char a, b;
    public:
    checkerboard(char a, char b) : a(a), b(b) {}
    char char_at(uint, uint, uint, uint) const override;
    widget* copy() const override { return new checkerboard(this -> a, this -> b); };
};

class stretchy : public widget{
    public:
    stretchy() {}
    char char_at(uint, uint, uint, uint) const override;
    widget* copy() const override { return new stretchy(); };
};

class two_widget_container : public widget{ // Contains some widgets. Abstract.
    protected:
    widget* first, * second;
    public:
    two_widget_container(widget* f, widget* s) : first(f), second(s) {}
    two_widget_container& operator=(two_widget_container const&); // sign operator
    virtual ~two_widget_container() { delete this -> first; delete this -> second; }
};

class vertical_split : public two_widget_container{
    //widget* top, * bottom; // If you want to decl ptr in same line, add * at that elem.
    public:
    vertical_split(widget* t, widget* b) : two_widget_container(t, b) {} // Due to rule of 3, we need signed operator.
    vertical_split(vertical_split const&); // copy constructor
    char char_at(uint, uint, uint, uint) const override;
    widget* copy() const override { return new vertical_split(this -> first -> copy(), this -> second -> copy()); };
};

class overlapping : public two_widget_container{
    public:
    overlapping(widget* back, widget* front) : two_widget_container(back, front) {}
    overlapping(overlapping const& other) : two_widget_container(other.first -> copy(), other.second -> copy()) {}
    char char_at(uint, uint, uint, uint) const override;
    widget* copy() const override { return new overlapping(this -> first -> copy(), this -> second -> copy()); }
};

class window : public widget{
    widget* base;
    public:
    window(widget* b) : base(b) {}
    window(window const& w) : base(w.base -> copy()) {}
    window& operator=(window const& other) { delete this -> base; this -> base = other.base->copy(); return *this; }
    widget* copy() const override { return new window(this -> base -> copy()); }
    char char_at(uint, uint, uint, uint) const override;
    ~window() { delete this -> base; }
};

#endif