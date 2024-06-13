#include "file.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	file *f[] = { new text_file(10000),
		new regular_file(8191),
		new video_stream(17.3),
		new video_stream(12.9, 950000) };
	directory d(f, sizeof f / sizeof *f);
	directory e = d;
	d = e;
	cout << d.blocks_required() << endl;
	return 0;
}
