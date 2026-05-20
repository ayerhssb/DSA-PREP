class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if(n==0){return false;}
        while(n){
            int rem=n%2;
            if(rem!=1){return false;}
            n=n/2;
        }
        return true;
    }
};
