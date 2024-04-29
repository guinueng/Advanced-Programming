#include "audio-file.h"
#include "wav-file.h"

using namespace std;

audio_file::audio_file(string f) : filename(f), buf_start_offset(0) {
    wav_file_data(f, this -> buf, 0, min( sizeof(this -> buf) / sizeof(this -> buf[0]), this -> num_samples() ));
}

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


short audio_file::operator[](size_t i){
    if(i >= this -> buf_start_offset && i < this -> buf_start_offset + sizeof(this -> buf) / sizeof(this -> buf[0]))
        return this -> buf[i - this -> buf_start_offset];
    
    this -> buf_start_offset = i;
    wav_file_data(this -> filename, this -> buf, i, min(sizeof(this -> buf) / sizeof(this -> buf[0]), this -> num_samples() - i));
    return this -> buf[0];
}