class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        if(n<=8){
            return n;
        }
        else if(n>8 && n<=16){
            return 8+(n-8)*2;
        }
        else if(n>16 && n<=24){
            return 24+(n-16)*3;
        }
        else{
            return 48 + (n-24)*4;
        }
        return 0;
    }
};
