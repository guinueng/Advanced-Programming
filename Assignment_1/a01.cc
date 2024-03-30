#include <iostream>
#include <iomanip> // To use abs function.
#include <cstring> // To use strlen function.
#include "wav-file.h"
using namespace std;

static size_t find_silence(string filename, double* times, size_t max_n){
    size_t wav_len = 0; // Need to store total wav length.
    size_t wav_sample_rate = 0; // Need to store sample rate of wav.
    size_t pos_qty = 0;
    size_t peak_amplitude = 0;
    size_t t_count = 0;

    // Part that calculates length and sample rate of wav.
    wav_file_info(filename, &wav_len, &wav_sample_rate);
    cout << wav_len << " " << wav_sample_rate << endl;

    // Part that brings partial part of wav.
    //size_t tmp_size = wav_sample_rate; // Calculate length of 1.5s.
    size_t offset = 0;
    //cout << tmp_size << endl;
    size_t i = 0;
    for(size_t i = 0; i < (wav_len / wav_sample_rate) * 2; i++){
        short tmp_sample[wav_sample_rate]; // Temporary array to store data of 1.5s audio due to sample rate.
        size_t count = 0; // Calculate length of silence.
        size_t start_pos = 0;
        cout << "Offset : " << offset << endl;
        if( (wav_len - offset + wav_sample_rate) <= wav_sample_rate){
            size_t mod_length = (wav_len - offset + wav_sample_rate);
            cout << "Mod : " << mod_length << endl;
            wav_file_data(filename, tmp_sample, offset, mod_length);
        }
        else
            wav_file_data(filename, tmp_sample, offset, wav_sample_rate);

        for(size_t t = 0; t < wav_sample_rate; t++){
            size_t amplitude = abs(tmp_sample[t]);

            if(peak_amplitude < amplitude)
                peak_amplitude = amplitude;
            //cout << "Amplitude : " << amplitude;
            if(amplitude < 1000){
                if(count == 0)
                    start_pos = (offset + t);
                count++;
            }
            else{
                //cout << "Count : " << count << endl;
                if(count >= wav_sample_rate * 0.5){
                    cout << "Start pos : " << start_pos << endl;
                    double init_pos = (double)((double)start_pos / (double)wav_sample_rate);
                    cout << "Pos : " << init_pos << endl;
                    
                    times[t_count] = init_pos;
                    t_count++;
                }

                count = 0;
            }
        }

        offset += (wav_sample_rate * 0.5);
    }

    return peak_amplitude;
}

int main (){
    // Need to print peak amplitude and list of starting time of silence(s) -> Duration is at least 0.5s.
    string filename;
    cout << "Enter filename: " << flush; // Part that program asks target wav file name.
    cin >> filename;

    // Part that making needed variables.
    size_t max_amplitude = 0; // Need to print maximum amplitude.
    double silence_pos[10] = {}; // Need to print out starting times of periods of silence.
    
    size_t peak_amplitude = find_silence(filename, &silence_pos[0], 10);

    cout << "Peak amplitude: " << peak_amplitude << endl;

    cout << "Periods of silence: " << endl;
    cout << setprecision(4) << fixed;
    for(size_t i = 0; i < 10; i++){
        cout << silence_pos[i] << endl;
    }

    return 0;
}