#include "file.h"
#include <vector>

using namespace std;

directory::~directory(){
    for(file* f : this -> files)
        delete f;
}

directory::directory(directory const& other) : files(){
    for(file* f : other.files)
        this -> files.push_back(f -> copy());
}

directory& directory::operator=(directory const& other){
    while(this -> files.size() > 0){
        delete this -> files[this -> files.size() - 1];
        this -> files.pop_back();
    }
    for(file* f : other.files)
        this -> files.push_back(f -> copy());
    return *this;
}

size_t directory::blocks_required() const{
    size_t r = 1; // directory holds 1 blocks.
    for(file* f : this -> files)
        r += f -> blocks_required();
    return r;
}

file* directory::copy() const{
    vector<file*> fs;
    for(file* f : this -> files)
        fs.push_back(f -> copy());
    return new directory(fs);
}