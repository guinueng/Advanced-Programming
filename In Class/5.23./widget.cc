#include "widget.h"

char label::char_at(uint x, uint y, uint w, uint h) const { // left aligned.
    if(x + 3 >= w && y == 0 && this -> text.size() > w)
        return '.';
    else if(y != 0 || x >= this -> text.size())
        return ' ';
    else
        return this -> text[x];
}

char checkerboard::char_at(uint x, uint y, uint w, uint h) const{
    if((x + y) % 2 == 0) // x + y is even/ which x, y both even or odd.
        return this -> a;
    else
        return this -> b;
}

char stretchy::char_at(uint x, uint y, uint w, uint h) const{ 
    if(y == 0 || y == h - 1) // First row of top and bottom.
        return '.';
    else if(y == 1 || y == h - 2) // Second row of top and bottom;
        return ':';
    else
        return '|';
}

vertical_split::vertical_split(vertical_split const& other) : two_widget_container(other.first -> copy(), other.second -> copy()) {}

two_widget_container& two_widget_container::operator=(two_widget_container const& other){
    delete this -> first;
    delete this -> second;
    this -> first = other.first -> copy();
    this -> second = other.second -> copy();
    return *this;
}

char vertical_split::char_at(uint x, uint y, uint w, uint h) const{
    if(y < h / 2)
        return this -> first -> char_at(x, y, w, h / 2);
    else
        return this -> second -> char_at(x, y - h / 2, w, h - h / 2);
}

char overlapping::char_at(uint x, uint y, uint w, uint h) const{
    if(x >= w / 3 && y >= h / 3)
        return this -> second -> char_at(x - w / 3, y - h / 3, w - w / 3, h - h / 3);
    else if(x <= 2 * w / 3 && y <= 2 * h / 3)
        return this -> first -> char_at(x, y, 2 * w / 3 + 1, 2 * h / 3 + 1);
    else
        return ' ';
}

char window::char_at(uint x, uint y, uint w, uint h) const{
    if(y == 0 || y == h - 1){
        if(x == 0 || x == w - 1)
            return '+';
        else
            return '-'; 
    }
    else if(x == 0 || x == w - 1)
        return '|';
    else
        return this -> base -> char_at(x - 1, y - 1, w - 2, h - 2);
}