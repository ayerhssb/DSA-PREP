
int helper(int n){
    if(n==0){return 0;}
    int log_base2_n = log(n)/log(2);
    int highest_power_of_two = floor(log_base2_n);
    int set_bits = (pow(2,highest_power_of_two-1)*highest_power_of_two) + (n+1 - pow(2,highest_power_of_two)) + (helper(n-pow(2,highest_power_of_two)));
    return set_bits;
}

int countSetBits(int n) {
    
    int ans=helper(n);
    return ans;
    // int ans=0;
    // vector<int> arr(n+1);
    // arr[0]=0;
    // for(int i=1;i<=n;i++){
    //         arr[i]=arr[i/2] + i%2;
    //         ans += arr[i];
    // }
    // return ans;
}
