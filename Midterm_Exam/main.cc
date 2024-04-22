#include "rpg.h"
#include <iostream>

using namespace std;

static bool is_in_group(character const* group, size_t n, character guy) {
	for (size_t i = 0; i < n; i++)
		if (group[i].walking_speed == guy.walking_speed && group[i].flying_speed == guy.flying_speed)
			return true;
	return false;
}

int main() {
	int num_passed = 0;
	character c;
#define CHECK_TS1(walk, fly, terr, exp)	c.walking_speed = walk; c.flying_speed = fly; if (travel_speed(&c, terr) != exp)	\
		cout << "Line " << __LINE__ << ": got " << travel_speed(&c, terr) << " instead of the expected " << exp << endl;	\
		else	num_passed++
	CHECK_TS1(9, 3, terrain_type::water, 3);
	CHECK_TS1(9, 3, terrain_type::sand, 5);
	CHECK_TS1(9, 3, terrain_type::volcano, 9);
	CHECK_TS1(10, 3, terrain_type::sand, 5);
	CHECK_TS1(2, 3, terrain_type::sand, 3);

	character const cs[] = { { 9, 3 }, { 10000, 10000 }, { 10, 8 }, { 5, 5 } };
	std::cout<<cs[0].flying_speed;
#define CHECK_TS2(cs, how_many, terr, exp)	if (travel_speed(cs, how_many, terr) != exp)	\
		cout << "Line " << __LINE__ << ": got " << travel_speed(cs, how_many, terr) << " instead of the expected " << exp << endl;	\
		else num_passed++
	CHECK_TS2(cs, 2, terrain_type::water, 3);
	CHECK_TS2(cs, 2, terrain_type::sand, 5);
	CHECK_TS2(cs, 2, terrain_type::volcano, 9);
	CHECK_TS2(cs, 4, terrain_type::water, 3);
	CHECK_TS2(cs, 4, terrain_type::sand, 5);
	CHECK_TS2(cs, 4, terrain_type::volcano, 5);
	CHECK_TS2(cs + 1, 3, terrain_type::water, 5);
	CHECK_TS2(cs + 1, 3, terrain_type::sand, 5);
	CHECK_TS2(cs + 1, 3, terrain_type::volcano, 5);

	terrain_type const ts[] = { terrain_type::water, terrain_type::sand, terrain_type::volcano, terrain_type::water, terrain_type::volcano,
		terrain_type::sand };
#define CHECK_TS3(cs, cs_n, ts, ts_n, exp)	if (travel_speed(cs, cs_n, ts, ts_n) != exp)	\
		cout << "Line " << __LINE__ << ": got " << travel_speed(cs, cs_n, ts, ts_n) << " instead of the expected " << exp << endl;	\
		else num_passed++
	CHECK_TS3(cs, 2, ts, 1, 3);
	CHECK_TS3(cs, 2, ts + 1, 1, 5);
	CHECK_TS3(cs, 2, ts + 2, 1, 9);
	CHECK_TS3(cs, 2, ts, 6, 3 + 5 + 9 + 3 + 9 + 5);
	CHECK_TS3(cs, 4, ts, 6, 3 + 5 + 5 + 3 + 5 + 5);

	character out[3];
#define CHECK_REMOVE(ts, ts_n, exp1, exp2, exp3)	if (remove_slowest(cs, out, sizeof cs / sizeof cs[0], ts, ts_n), is_in_group(out, 3, exp1) && is_in_group(out, 3, exp2) && is_in_group(out, 3, exp3))	num_passed++; else if (!is_in_group(out, 3, exp1))	\
		cout << "Line: " << __LINE__ << ": { " << exp1.walking_speed << ", " << exp1.flying_speed << " } should be in the group" << endl; else if (!is_in_group(out, 3, exp2))	\
		cout << "Line: " << __LINE__ << ": { " << exp2.walking_speed << ", " << exp2.flying_speed << " } should be in the group" << endl; else if (!is_in_group(out, 3, exp3))	\
		cout << "Line: " << __LINE__ << ": { " << exp3.walking_speed << ", " << exp3.flying_speed << " } should be in the group" << endl
	CHECK_REMOVE(ts, 1, cs[0], cs[1], cs[2]);
	CHECK_REMOVE(ts, 2, cs[0], cs[1], cs[2]);
	CHECK_REMOVE(ts, 3, cs[0], cs[1], cs[3]);
	CHECK_REMOVE(ts, 4, cs[0], cs[1], cs[3]);
	CHECK_REMOVE(ts, 5, cs[0], cs[1], cs[3]);
	CHECK_REMOVE(ts, 6, cs[0], cs[1], cs[3]);

	cout << num_passed << "/25 test cases passed" << endl;

	return 0;
}
