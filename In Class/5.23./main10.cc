#include "widget.h"
#include <iostream>

using namespace std;

static void print(ostream &out, widget const &root, unsigned int w, unsigned int h) {
	for (unsigned int y = 0; y < h; y++) {
		for (unsigned int x = 0; x < w; x++)
			out << root.char_at(x, y, w, h);
		out << '\n';
	}
	out << flush;
}

int main(){
    widget* vs_back = new vertical_split(new label("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"), new window(new stretchy()));
    widget* back = new window(new vertical_split(vs_back, vs_back -> copy()));
    widget* front = new window(new overlapping(new checkerboard('.', '.'), new window(new stretchy())));
    widget* w = new overlapping(back, front);
    print(cout, *w, 60, 30);
    delete w;
    return 0;
}