#include <iostream>
#include <climits>
#include <cassert>
using namespace std;

static size_t subset_sum(long const* xs, size_t xs_n, long target, long* out){
    if(target < 0)  return SIZE_MAX;
    if(target == 0) return 0; // Indicate solution has 0 elem.
    assert(target > 0);
    if(xs_n == 0)    return SIZE_MAX;

    size_t rec_solution = subset_sum(xs, xs_n - 1, target, out); // Last elem is not the subset of target.
    if(rec_solution != SIZE_MAX) // Found satisfying case w/o containing last elem.
        return rec_solution;
    rec_solution = subset_sum(xs, xs_n - 1, target - xs[xs_n - 1], out);
    if(rec_solution == SIZE_MAX)
        return SIZE_MAX;
    out[rec_solution] = xs[xs_n - 1];
    return rec_solution + 1;
} // Complexity 2^n due to each elem has 2 cases.

/* By using bit shifting. Complexity 2^n due to outer loop case.
static size_t subset_sum(long const* xs, size_t xs_n, long target, long* out){
    assert(xs_n <= sizeof (unsigned long) * CHAR_BIT);
    for(unsigned long subset_pat = 0; subset_pat < (1ul << xs_n); subset_pat++){ // 1ul is 1 unsigned long | << is shifting binary upwards = same as multiplying 2 like power of 2. It will loop 2^n.
        long sum = 0;
        for(size_t i = 0; i < xs_n; i++)
            if((subset_pat >> i) & 1) // Checking bits. If right shift, what we want to check binary is the rightmost position.
                sum += xs[i];
        if(sum == target){
            size_t out_i = 0;
            for(size_t i = 0; i < xs_n; i++)
                if((subset_pat >> i) & 1){
                    out[out_i] = xs[i];
                    out_i++;
                }
            return out_i;
        }
    }
    return SIZE_MAX;
}
*/

int main (){
    long const xs[] = {2, 3, 7, 8, 11, 14, 20, 33, 34, 37};
    long subset[50];

    size_t subset_n = subset_sum(xs, sizeof xs / sizeof xs[0], 58, subset);
    if(subset_n == SIZE_MAX)
        cout << "No solution" << endl;
    else{
        for(size_t i = 0; i < subset_n; i++)
            cout << subset[i] << " ";
        cout << endl;
    }

    return 0;
}

// Add const on assignment 1!