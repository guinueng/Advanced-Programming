#ifndef AUDIO_FILE_H
#define AUDIO_FILE_H

#include <string>

class audio_file{
    std::string filename;

    public:
    audio_file(std::string f) : filename(f) {}
    size_t num_samples() const;
    unsigned long sampling_rate() const;
    short operator[](size_t) const;

};

#endif