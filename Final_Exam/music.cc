#include "music.h"
#include <cstddef>

note transpose_note(note n, int a) {
	int tmp = ((int)n + a) % 12;
	if(tmp < 0)
		tmp += 12;
	return (note)tmp;
}

interval::interval(interval const& other){
	this -> first = other.first;
	this -> val = other.val;
}

interval& interval::operator=(interval const& other){
	this -> first = other.first;
	this -> val = other.val;
	return *this;
}

bool interval::contains_note(note n) const{
	if(this -> first == n || transpose_note(this -> first, this -> val ) == n)
		return true;
	else
		return false;
}

musical_element* interval::transpose(int n){
	note tmp_f = transpose_note(this -> first, n);
	musical_element *tmp = new interval(tmp_f, this -> val);
	return tmp;
}

major_chord::major_chord(major_chord const& other){
	this -> root = other.root;
}

major_chord& major_chord::operator=(major_chord const& other){
	this -> root = other.root;
	return *this;
}

bool major_chord::contains_note(note n) const{
	if(this -> root == n || transpose_note(this -> root, 4) == n || transpose_note(this -> root, 7) == n)
		return true;
	else
		return false;
}

musical_element* major_chord::transpose(int n){
	note tmp_r = transpose_note(this -> root, n);
	musical_element *tmp = new major_chord(tmp_r);
	return tmp;
}

minor_chord::minor_chord(minor_chord const& other){
	this -> root = other.root;
}

minor_chord& minor_chord::operator=(minor_chord const& other){
	this -> root = other.root;
	return *this;
}

bool minor_chord::contains_note(note n) const{
	if(this -> root == n || transpose_note(this -> root, 3) == n || transpose_note(this -> root, 7) == n)
		return true;
	else
		return false;
}

musical_element* minor_chord::transpose(int n){
	note tmp_r = transpose_note(this -> root, n);
	musical_element *tmp = new minor_chord(tmp_r);
	return tmp;
}

dominant_seventh::dominant_seventh(dominant_seventh const& other){
	this -> root = other.root;
}

dominant_seventh& dominant_seventh::operator=(dominant_seventh const& other){
	this -> root = other.root;
	return *this;
}

bool dominant_seventh::contains_note(note n) const{
	if(this -> root == n || transpose_note(this -> root, 4) == n || transpose_note(this -> root, 7) == n || transpose_note(this -> root, 10) == n)
		return true;
	else
		return false;
}

musical_element* dominant_seventh::transpose(int n){
	note tmp_r = transpose_note(this -> root, n);
	musical_element *tmp = new dominant_seventh(tmp_r);
	return tmp;
}

misc_chord& misc_chord::operator+=(musical_element& other){
	this -> elems.push_back(other.transpose(0));
	return *this;
}

misc_chord& misc_chord::operator=(misc_chord const& other){
	while(this -> elems.size() > 0){
		delete this -> elems[this -> elems.size() - 1];
		this -> elems.pop_back();
	}

	for(size_t i = 0; i < other.elems.size(); i++)
		this -> elems.push_back(other.elems[i]);

	return *this;
}

bool misc_chord::contains_note(note n) const{
	for(size_t i = 0; i < this -> elems.size(); i++)
		if(this -> elems[i] -> contains_note(n) == true)
			return true;

	return false;
}

musical_element* transpose(int){
	
}
