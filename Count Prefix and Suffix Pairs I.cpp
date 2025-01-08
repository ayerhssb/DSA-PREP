class Solution {
public:

    bool isPrefixAndSuffix(string& str1, string& str2){
            int pre=0,suf=0;
            int n=str1.size(),m=str2.size();
            if(n>m){return false;}
            for(int i=0;i<n;i++){
                if(str1[i]==str2[i]){
                    pre++;
                }
                if(str1[n-i-1]==str2[m-i-1]){
                    suf++;
                }
            }

            if(pre==n && suf==n){
                return true;
            }
        return false;    
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(isPrefixAndSuffix(words[i],words[j])){cnt++;}
            }
        }
        return cnt;
    }
};
