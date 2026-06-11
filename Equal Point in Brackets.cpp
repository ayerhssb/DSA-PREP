class Solution {
  public:
    int findIndex(string &s) {
        int n=s.size(), totalopen=0, open=0, totalclose=0, close=0, k=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                totalopen++;
            }
            else{
                totalclose++;
            }
        }
        
        while(k<n){
            if(k=='('){
                open++;
            }else{
                close++;
            }
            
            if(open== totalclose-close){
                return k+1;
            }
            k++;
        }
        return 0;
    }
};
