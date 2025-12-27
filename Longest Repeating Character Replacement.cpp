class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mpp;
        int l=0,r=0,cnt=0,maxi=INT_MIN;
        while(r<s.size()){
            mpp[s[r]]++;
            int len = r-l+1,mostFreq=0;
            for(auto it:mpp){
                mostFreq=max(mostFreq,it.second);
            }
            if(len-mostFreq<=k){int ans=r-l+1;maxi=max(maxi,ans);}
            else{mpp[s[l]]--;l++;}
            r++;
        }
        return maxi;
    }
};
