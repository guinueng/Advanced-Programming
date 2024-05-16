#include "widget.h"

char label::char_at(uint x, uint y, uint w, uint h) const { // left aligned.
    if(x + 3 >= w && y == 0 && this -> text.size() > w)
        return '.';
    else if(y != 0 || x > this -> text.size())
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

char vertical_split::char_at(uint x, uint y, uint w, uint h) const{
    if(y < h / 2)
        return this -> top -> char_at(x, y, w, h);
    else
        return this -> bottom -> char_at(x, y - h / 2, w, h);
}