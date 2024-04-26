#include "audio-file.h"
#include <iostream>
#include <algorithm>

using namespace std;

short peak_amplitude(audio_file const& audio){
    short m = 0;
    for(size_t i = 0; i < audio.num_samples(); i++)
        m = max(m, abs(audio[i]));

    return m;
}

int main(){
    cout << "Enter filename : " << flush;
    string filename;
    cin >> filename;
    
    audio_file audio = filename;
    cout << peak_amplitude(audio) << endl;
    
    double silence_start[10];
    size_t num_silence = find_silence(audio, silence_start, 10);
    for (size_t i = 0; i < 10; i++){
        cout << silence_start[i] << "\n";
    }

    return 0;
}