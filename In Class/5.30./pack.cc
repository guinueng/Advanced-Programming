#include <iostream>
#include <algorithm> // for min, max;
#include <cstdlib>
#include <numeric>
#include <vector>

using namespace std;

static size_t pack (double const* ls, size_t n, double bin_size, vector<vector<double>>& bins){
    if(n == 0)
        return bins.size();

    bins.push_back(vector<double>{ ls[0] }); // Making new bean pocket.
    size_t best_n = pack(ls + 1, n - 1, bin_size, bins);
    vector<vector<double>> best = bins;
    bins.pop_back();
    for(size_t i = 0; i < bins.size(); i++){
        if(accumulate(bins[i].begin(), bins[i].end(), 0) + ls[0] <= bin_size){
            bins[i].push_back(ls[0]); // Add bins into existing pocket.
            size_t this_n = pack(ls + 1, n - 1, bin_size, bins);
            if(this_n < best_n){
                best_n = this_n;
                best = bins;
            }
            bins[i].pop_back();
        }
    }
    bins = best;
    return best_n;
}

int main(int argc, char** argv){ // C does not have string type, cause it denotes array of character, thus it is char**
    double bin_size = strtod(argv[1], nullptr); // string to double.
    vector<double> lengths;
    while(true){
        double x;
        cin >> x;
        if(!cin)
            break;
        lengths.push_back(x);
    }
    for (double x : lengths)
        cout << x << " ";
    cout << endl;

    vector<vector<double>> bins;
    size_t num_bins = pack(lengths.data(), lengths.size(), bin_size, bins);

    cout << "Packed it in " << num_bins << "bins." << endl;

    return 0;
}