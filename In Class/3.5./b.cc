long fact(long n){
    long ans = 1;
    for(long i = 1; i <= n; i++){
        ans *= i;
    }

    return ans;
}