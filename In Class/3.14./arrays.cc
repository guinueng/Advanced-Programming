#include <iostream>

int main(){
    using namespace std;
    double xs[] = {3, 7, -19.5, 32, 1e38, -3.2e-16, 1234, 271};
    double sum = 0;
    for(size_t i = 0; i < 50; i++)
        sum += xs[i];
    cout << sum << endl;
    return 0;
}

// SANFLAGS = -fsanitize=address > Using address sanitizer
// Using sanitizer as compiling and linking by adding flags.
// stack-buffer-overflow
// = arr is saved on stack / 
// If add. san. is not giving enough info, check cxxflags has -g option.