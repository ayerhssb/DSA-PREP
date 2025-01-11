class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int maxi=0, start=0;
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end() && mp[s[i]] >=start){
                start = mp[s[i]]+1;
            }
            
            mp[s[i]]=i;
            
            maxi = max(i-start+1,maxi);
        }
        return maxi;
    }
};
