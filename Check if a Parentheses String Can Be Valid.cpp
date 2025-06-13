class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n%2!=0){return false;}
        int op=0, cl=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('|| locked[i]=='0'){
                op++;
            }
            else{
                op--;
            }
            if(op<0){return false;}
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]==')'|| locked[i]=='0'){
                cl++;
            }
            else{
                cl--;
            }
            if(cl<0){return false;}
        }
        return true;
    }
};
