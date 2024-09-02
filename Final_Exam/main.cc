#include "music.h"
#include <iostream>

using namespace std;

static void check_q1() {
	int right = 0, total = 0;
#define CHECK(val, expected)	total++; if (val == expected) right++; else cerr << "Line " << __LINE__ << ": expected " << (int)expected << " but got " << (int)val << endl
	note n = note::Gb;
	CHECK(transpose_note(n, 1), note::G);
	CHECK(transpose_note(n, 2), note::Ab);
	CHECK(transpose_note(n, 3), note::A);
	n = note::C;
	CHECK(transpose_note(n, 0), note::C);
	CHECK(transpose_note(n, 2), note::D);
	CHECK(transpose_note(n, -1), note::B);
	CHECK(transpose_note(n, -2), note::Bb);
	CHECK(transpose_note(n, -3), note::A);
	CHECK(transpose_note(n, -4), note::Ab);
	CHECK(transpose_note(n, 8), note::Ab);
#undef CHECK
	cout << "Q1: " << right << "/" << total << " passed" << endl;
}

static void check_q2() {
	int right = 0, total = 0;
#define CHECK(i, note, v)	total++; if ((i).contains_note(note) == v) right++; else cerr << "Line " << __LINE__ << " is wrong" << endl
	interval i1(note::C, 5);
	CHECK(i1, note::C, true);
	CHECK(i1, note::Db, false);
	CHECK(i1, note::F, true);
	interval i2 = i1;
	CHECK(i2, note::F, true);
	CHECK(i2, note::Gb, false);
	musical_element* i3 = i2.transpose(1);
	CHECK(*i3, note::Gb, true);
	CHECK(*i3, note::F, false);
	CHECK(*i3, note::C, false);
	CHECK(*i3, note::Db, true);
	delete i3;
#undef CHECK
	cout << "Q2: " << right << "/" << total << " passed" << endl;
}

static void check_q3() {
	int right = 0, total = 0;
#define CHECK(i, note, v)	total++; if ((i).contains_note(note) == v) right++; else cerr << "Line " << __LINE__ << " is wrong" << endl
	major_chord c = note::C;
	CHECK(c, note::C, true);
	CHECK(c, note::E, true);
	CHECK(c, note::G, true);
	CHECK(c, note::Ab, false);
	musical_element* ab = c.transpose(-4);
	CHECK(*ab, note::Ab, true);
	CHECK(*ab, note::C, true);
	CHECK(*ab, note::Eb, true);
	CHECK(*ab, note::A, false);
	delete ab;
	major_chord eb = note::Eb;
	CHECK(eb, note::Bb, true);
	musical_element* f = eb.transpose(2);
	CHECK(*f, note::F, true);
	CHECK(*f, note::A, true);
	CHECK(*f, note::C, true);
	delete f;
#undef CHECK
	cout << "Q3: " << right << "/" << total << " passed" << endl;
}

static void check_q4() {
	int right = 0, total = 0;
#define CHECK(i, note, v)	total++; if ((i).contains_note(note) == v) right++; else cerr << "Line " << __LINE__ << " is wrong" << endl
	minor_chord c = note::C;
	CHECK(c, note::C, true);
	CHECK(c, note::E, false);
	CHECK(c, note::Eb, true);
	CHECK(c, note::G, true);
	CHECK(c, note::Ab, false);
	musical_element* ab = c.transpose(-4);
	CHECK(*ab, note::Ab, true);
	CHECK(*ab, note::C, false);
	CHECK(*ab, note::B, true);
	CHECK(*ab, note::Eb, true);
	CHECK(*ab, note::A, false);
	delete ab;
	minor_chord f = note::F;
	CHECK(f, note::F, true);
	CHECK(f, note::A, false);
	CHECK(f, note::Ab, true);
	CHECK(f, note::C, true);
#undef CHECK
	cout << "Q4: " << right << "/" << total << " passed" << endl;
}

static void check_q5() {
	int right = 0, total = 0;
#define CHECK(i, note, v)	total++; if ((i).contains_note(note) == v) right++; else cerr << "Line " << __LINE__ << " is wrong" << endl
	dominant_seventh c = note::C;
	CHECK(c, note::C, true);
	CHECK(c, note::E, true);
	CHECK(c, note::G, true);
	CHECK(c, note::Bb, true);
	CHECK(c, note::B, false);
	musical_element* gb = c.transpose(6);
	CHECK(*gb, note::A, false);
	CHECK(*gb, note::Bb, true);
	CHECK(*gb, note::B, false);
	CHECK(*gb, note::C, false);
	CHECK(*gb, note::Db, true);
	CHECK(*gb, note::D, false);
	CHECK(*gb, note::Eb, false);
	CHECK(*gb, note::E, true);
	CHECK(*gb, note::F, false);
	CHECK(*gb, note::Gb, true);
	CHECK(*gb, note::G, false);
	CHECK(*gb, note::Ab, false);
	delete gb;
#undef CHECK
	cout << "Q5: " << right << "/" << total << " passed" << endl;
}

static void check_q6() {
	int right = 0, total = 0;
#define CHECK(i, note, v)	total++; if ((i).contains_note(note) == v) right++; else cerr << "Line " << __LINE__ << " is wrong" << endl
	interval i1(note::E, 2);
	major_chord db = note::Db;
	misc_chord c;
	c += i1;
	c += db;
	misc_chord d = c;
	CHECK(c, note::A, false);
	CHECK(c, note::Bb, false);
	CHECK(c, note::B, false);
	CHECK(c, note::C, false);
	CHECK(c, note::Db, true);
	CHECK(c, note::D, false);
	CHECK(c, note::Eb, false);
	CHECK(c, note::E, true);
	CHECK(c, note::F, true);
	CHECK(c, note::Gb, true);
	CHECK(c, note::G, false);
	CHECK(c, note::Ab, true);
	musical_element* c2 = c.transpose(-1);
	CHECK(*c2, note::A, false);
	CHECK(*c2, note::Bb, false);
	CHECK(*c2, note::B, false);
	CHECK(*c2, note::C, true);
	CHECK(*c2, note::Db, false);
	CHECK(*c2, note::D, false);
	CHECK(*c2, note::Eb, true);
	CHECK(*c2, note::E, true);
	CHECK(*c2, note::F, true);
	CHECK(*c2, note::Gb, false);
	CHECK(*c2, note::G, true);
	CHECK(*c2, note::Ab, false);
	delete c2;

	musical_element* i2 = interval(note::D, 3).transpose(3);
	misc_chord c1;
	c1 += *i2;
	misc_chord *c4 = (misc_chord*)c1.transpose(1);
	*c4 += *i2;
	musical_element* c3 = c4->transpose(4);
	*c4 += *c3;
	delete c3;
	delete i2;
	CHECK(*c4, note::A, true);
	CHECK(*c4, note::Bb, true);
	CHECK(*c4, note::B, false);
	CHECK(*c4, note::C, true);
	CHECK(*c4, note::Db, true);
	CHECK(*c4, note::D, false);
	CHECK(*c4, note::Eb, false);
	CHECK(*c4, note::E, false);
	CHECK(*c4, note::F, true);
	CHECK(*c4, note::Gb, true);
	CHECK(*c4, note::G, false);
	CHECK(*c4, note::Ab, true);
	delete c4;
#undef CHECK
	cout << "Q6: " << right << "/" << total << " passed" << endl;
}

int main() {
	check_q1();
	check_q2();
	check_q3();
	check_q4();
	check_q5();
	check_q6();
	return 0;
}
