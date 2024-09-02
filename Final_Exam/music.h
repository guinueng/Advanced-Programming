#ifndef MUSIC_H
#define MUSIC_H
#include <vector>

enum class note { A, Bb, B, C, Db, D, Eb, E, F, Gb, G, Ab };

note transpose_note(note, int);

class musical_element {
public:
	virtual ~musical_element() {}
	virtual bool contains_note(note) const { return false; }
	virtual musical_element* transpose(int n) { return this; }
};

class interval : public musical_element {
protected:
	note first;
	int val;
public:
	interval(note root, int val) : first(root), val(val) {}
	interval(interval const& other);
	interval& operator=(interval const& other);
	bool contains_note(note) const override;
	musical_element* transpose(int) override;
};

class major_chord : public musical_element {
protected:
	note root;
public:
	major_chord(note root) : root(root) {}
	major_chord(major_chord const& other);
	major_chord& operator=(major_chord const& other);
	bool contains_note(note) const override;
	musical_element* transpose(int) override;
};

class minor_chord : public musical_element {
protected:
	note root;
public:
	minor_chord(note root) : root(root) {}
	minor_chord(minor_chord const& other);
	minor_chord& operator=(minor_chord const& other);
	bool contains_note(note) const override;
	musical_element* transpose(int) override;
};

class dominant_seventh : public musical_element {
protected:
	note root;
public:
	dominant_seventh(note root) : root(root) {}
	dominant_seventh(dominant_seventh const& other);
	dominant_seventh& operator=(dominant_seventh const& other);
	bool contains_note(note) const override;
	musical_element* transpose(int) override;
};

class misc_chord : public musical_element {
protected:
	std::vector<musical_element *> elems;
public:
	misc_chord() {}
	//misc_chord& operator+=(musical_element const&) { return *this; };
	misc_chord& operator+=(musical_element&);
	misc_chord& operator=(misc_chord const&);
	bool contains_note(note) const override;
	musical_element* transpose(int) override;
};

#endif
