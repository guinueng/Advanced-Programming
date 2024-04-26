#include "audio-file.h"
#include "wav-file.h"

using namespace std;

size_t audio_file::num_samples() const{
    size_t len;
    unsigned long unused;
    wav_file_info(this -> filename, &len, &unused);

    return len;
}


unsigned long audio_file::sampling_rate() const{
    size_t unused;
    unsigned long r;
    wav_file_info(this -> filename, &unused, &r);

    return r;
}


short audio_file::operator[](size_t i) const{
    short sample;
    wav_file_data(this -> filename, &sample, i, 1);
    
    return sample;
}