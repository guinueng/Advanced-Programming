#include "file.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<file *> f;
	f.push_back(new text_file(10000));
	f.push_back(new regular_file(8191));
	f.push_back(new video_stream(17.3));
	f.push_back(new video_stream(12.9, 950000));
	directory d(f);
	directory e = d;
	d = e;
	cout << d.blocks_required() << endl;
	return 0;
}
