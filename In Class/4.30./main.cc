#include "audio-file.h"
#include <iostream>
#include <algorithm>

using namespace std;

short peak_amplitude(audio_file& audio){
    short m = 0;
    size_t const n = audio.num_samples();
    for(size_t i = 0; i < n; i++)
        m = max(m, (short)abs(audio[i]));

    return m;
}

size_t find_silence(audio_file& audio, double* starts, size_t max_n){
    size_t starts_i = 0;
    bool in_silence = false;
    size_t silence_start;
    size_t const n = audio.num_samples();
    for(size_t i = 0; i < n; i++){
        if(abs(audio[i]) <= 1000 && !in_silence){
            in_silence = true;
            silence_start = i;
        }
        else if(in_silence && (abs(audio[i]) > 1000 || i == n - 1)){
            in_silence = false;
            double const duration = (i - silence_start) / (double)audio.sampling_rate();
            if(duration >= 0.5 && starts_i < max_n){
                starts[starts_i] = silence_start / (double)audio.sampling_rate();
                starts_i++;
            }
        }
    }

    return starts_i;
}

int main(){
    cout << "Enter filename : " << flush;
    string filename;
    cin >> filename;
    
    audio_file audio = filename;
    cout << peak_amplitude(audio) << endl;
    
    double silence_start[10];
    size_t num_silence = find_silence(audio, silence_start, 10);
    for (size_t i = 0; i < num_silence; i++){
        cout << silence_start[i] << "\n";
    }

    return 0;
}