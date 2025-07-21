class Solution {
  public:
    int helper(int a, int b){
        if(a==0){
            return b;
        }
        
        return helper(b%a, a);
    }
    int gcd(int n, vector<int> arr) {
        int res = arr[0];
        for(int i=1;i<n;i++){
            res = helper(res, arr[i]);
            
            if(res==1){
                return 1;
            }
        }
        
        return res;
    }
};
