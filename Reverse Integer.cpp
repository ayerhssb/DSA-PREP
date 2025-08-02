class Solution {
public:
    int reverse(int y) {
        int ans=0;
        while(y){
            if(ans>(INT_MAX/10) || ans< (INT_MIN/10)){return 0;}
            int rem=y%10;
            ans=ans*10 + rem;
            y=y/10;
        }
        return ans; 
    }
};
