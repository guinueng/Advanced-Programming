#include <iostream>

long find(int const *haystack, size_t haystack_size, int const *needle, size_t needle_size) {
	if ( needle_size == 0 )				return 0;
	if ( haystack_size < needle_size )	return -1;
	if ( haystack[0] == needle[0] && find(haystack + 1, haystack_size - 1, needle + 1, needle_size - 1) == 0 )
		return 0;
	else{
		long r = find(haystack + 1, haystack_size - 1, needle, needle_size);
		if (r == -1)	return -1;
		else			return 1 + r;
	}
}

int main() {
	// you should not remove or modify any of the given test cases
	// (you may add your own, if you wish, but it's not necessary)
	// you are not expected to understand the CHECK macro
	using namespace std;
#define CHECK(r)	do { cout << "Line " << __LINE__; long rr = find(h, sizeof h/sizeof *h, n, sizeof n/sizeof *n); if (r == rr) cout << " passed" << endl; else cout << " expected " << r << ", but got " << rr << endl; } while (0)
	{ int const h[] = {};                             int const n[] = {};             CHECK(0); }
	{ int const h[] = {};                             int const n[] = { 1 };          CHECK(-1); }
	{ int const h[] = { 0 };                          int const n[] = { 0 };          CHECK(0); }
	{ int const h[] = { 1, 2, 3 };                    int const n[] = { 1, 2, 3 };    CHECK(0); }
	{ int const h[] = { 2, 3 };                       int const n[] = { 1, 2, 3 };    CHECK(-1); }
	{ int const h[] = { 1, 2, 3 };                    int const n[] = { 2, 3 };       CHECK(1); }
	{ int const h[] = { 5, 8, 10, 12, -5, -6, 0, 5 }; int const n[] = { 12, -5, -6 }; CHECK(3); }
	{ int const h[] = { 9, 10, 14, 18, -5, -6 };      int const n[] = { 14, -5 };     CHECK(-1); }
	return 0;
}
