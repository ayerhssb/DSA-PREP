class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0,m=pref.size();
        for(int i=0;i<words.size();i++){
            int j=0;
            while(j<m){
                if(pref[j]==words[i][j]){j++;}
                else{break;}
            }
            if(j==m){cnt++;}
        }
        return cnt;
    }
};
