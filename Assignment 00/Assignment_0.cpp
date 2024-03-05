#include <iostream>

int main(){
    int num1, num2; // Define two integer variables to get two numbers.
    std::cin>>num1>>num2; // By using cin function, we can get two integer inside variables.

    if(num1 < num2){ // We have to print out positive value of two numbers difference.
        // Thus, we have to check which number is big.
        // Then subtract smaller one into bigger one to print out result.
        std::cout<<num2 - num1<<std::endl;
    }
    else{
        std::cout<<num1 - num2<<std::endl;
    }
    
    return 0;
}