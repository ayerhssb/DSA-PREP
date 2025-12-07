class Solution {
public:
    int countOdds(int low, int high) {
        int ans=0;
        // if(high==low){return ans;}
        if(low%2==0 && high%2==0){
            return (high-low)/2;
        }
        else if(low%2 && high%2){
            return ((high-low-2)/2 + 2);
        }
        else{
            return ((high-low-1)/2 + 1);
        }
    }
};
