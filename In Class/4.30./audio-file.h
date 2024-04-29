#ifndef AUDIO_FILE_H
#define AUDIO_FILE_H

#include <string>

class audio_file{
    std::string filename;
    short buf[1024];
    size_t buf_start_offset;    // Offset which buffered data starts.
    public:
    audio_file(std::string f);
    size_t num_samples() const;
    unsigned long sampling_rate() const;
    short operator[](size_t);

};

#endif