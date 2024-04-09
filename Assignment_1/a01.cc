#include <iostream>
#include <iomanip> // To use abs function.
#include <cstring> // To use strlen function.
#include "wav-file.h"
using namespace std;

static size_t find_silence(string filename, double* times, size_t max_n){
    size_t wav_len = 0; // Need to store total wav length.
    size_t wav_sample_rate = 0; // Need to store sample rate of wav.
    size_t peak_amplitude = 0; // Variable that we want to store maximum absolute value of amplitude.
    size_t t_count = 0; // Need it to check how many element we stored in times array.

    // Part that calculates length and sample rate of wav.
    wav_file_info(filename, &wav_len, &wav_sample_rate); // Bring total length and sample rate of given wav file.

    // Part that brings partial part of wav.
    size_t offset = 0; // Variables that how many offsets to calculate.
    bool lasting = false; // Condition to check silence is lasting another 0.5s or not.

    for(size_t i = 0; i < (wav_len / 1000) * 2; i++){
        short tmp_sample[1001]; // Temporary array to store data of 1.5s audio due to sample rate.
        size_t count = 0; // Calculate length of silence.
        size_t start_pos = 0; // Variable that I can store starting seconds of silence.
        size_t sample_size = 0; // Variable that I want to store how long that we have to calculate.
        
        if(offset + 1000 > wav_len) // If last part of data is smaller than given file's sample rate, calculate last length.
            sample_size = wav_len - offset - 44;
        else // If it does not or normal case, consider sample size as file's sample rate.
            sample_size = 1000;
        wav_file_data(filename, tmp_sample, offset, sample_size); // Bring wav_file_data.

        if(abs(tmp_sample[0]) >= 1000) // If first element of array is bigger than silence range, we can consider silence does not last.
            lasting = false;

        for(size_t t = 0; t < sample_size; t++){ // Calculating 1s duration, due to we check 0.5s duration with another 0.5s.
            size_t amplitude = abs(tmp_sample[t]); // Calculate amplitude by using abs function.

            if(peak_amplitude < amplitude) // If peak amplitude is lower than this position's amplitude, update the value.
                peak_amplitude = amplitude;

            if(amplitude < 1000){
                if(count == 0) // If first case of amplitude is inside of silence range, check starting seconds.
                    start_pos = (offset + t);
                count++; // Increase count to increase duration of silence.
                if(t == sample_size - 1 && count >= 1000 * 0.5 && t < offset + 1000 * 0.5 && lasting == false){
                    // If program checked last part of given range, and it is silence status.
                    // Also, it is away lower than 0.5s which we can check another 0.5s and does not last, we can consider it would be last and contain value into times array. 
                    lasting = true; // Set lasting true.
                    if(t_count < 10){ // Check if array is not full, and it is, fill the array with starting seconds.
                        times[t_count] = (double)start_pos / wav_sample_rate;
                        t_count++;
                    }
                    // If array is fulled do nothing.
                }
            }
            else{
                if(lasting){
                    if(t < wav_sample_rate * 0.5) // If before state was lasting but smaller than calculating range, which finishes lasting silence, change it as not lasting.
                        lasting = false;
                }
                else if(count >= wav_sample_rate * 0.5){
                    double init_pos = (double)start_pos / wav_sample_rate; // Calculate starting position.
                    
                    if(t_count < 10){ // If array has empty space, fill the value into array.
                        times[t_count] = init_pos;
                        t_count++;
                    }
                    // If array is fulled, do nothing.
                }
                count = 0; // Reset duration of silence as 0.
            }
            /*
                For first submission, I use break when array is fulled.
                But there's mis consideration that peak amplitude may update after array is fulled.
                Thus, I deleted return peak_amplitude during calculation of peak amplitude and silence.
            */
        }
        offset += (wav_sample_rate * 0.5); // Update check range as 0.5s increasing each elements.
    }
    // Return calculated peak_amplitude value.
    return peak_amplitude;
}

int main(){
    // Need to print peak amplitude and list of starting time of silence(s) -> Duration is at least 0.5s.
    string filename;
    cout << "Enter filename: " << flush; // Part that program asks target wav file name.
    cin >> filename;

    // Part that making needed variables.
    size_t max_amplitude = 0; // Need to print maximum amplitude.
    double silence_pos[10] = {-1}; // Need to print out starting times of periods of silence.
    
    size_t peak_amplitude = find_silence(filename, &silence_pos[0], 10); // Calculate starting second of silence and peak amplitude values.

    cout << "Peak amplitude: " << peak_amplitude << endl; // Print peak amplitude values.

    cout << "Periods of silence: " << endl; // Print starting position of silence.
    cout << setprecision(4) << fixed; // By using setprecision function, I can fix how many decimals that I want to print.
    // Citation from https://www.tutorialspoint.com/printing-the-correct-number-of-decimal-points-with-cout-in-cplusplus .
    for(size_t i = 0; i < 10; i++){ // Looping whole array to print values.
        if(silence_pos[i] > 0) // Due to array is initialized as 0, the value we want to print out would be over 0 except possible case that silence start first 0.5s.
            cout << silence_pos[i] << endl;
        else if(i == 0 && silence_pos[i] >= 0) // Possible case when first 0.5s is silence.
            cout << silence_pos[i] << endl;
        else // The other case that there does not have silence, after precious value would will be filled with 0. Thus we terminate for loop and stop prints.
            break;
    }

    return 0;
}
// Also using gdb debugger and using break option, I need to remove break point.
// By information from https://stackoverflow.com/questions/4340718/how-do-i-remove-a-single-breakpoint-with-gdb , I could found how to remove breakpoint.
