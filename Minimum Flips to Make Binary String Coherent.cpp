class Solution {
public:
    int minFlips(string s) {
        int n=s.size(), zero=0, one=0, ans=0,mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){zero++;}
            else{one++;}
        }
        cout<<"zero: "<<zero<<" one: "<<one<<endl;
        if(zero==0 || one==0){return 0;}
        
        if((s[0]=='1' && s[n-1]=='1') && one==2){return 0;}
        
        if(one>zero){
            ans= zero;
        }
        else{
            ans=one-1;
        }

        if(s[0]=='1' && s[n-1]=='1'){
            ans=min(ans,one-2);
        }
        
        return ans;
    }
};
