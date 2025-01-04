class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,pair<int,int>> mp;
        int cnt=0;

        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]].first=i;
                mp[s[i]].second=i;
            }
            else{
                mp[s[i]].second=i;
            }
        }

        for(auto it:mp){
            set<int> set1;
            if(it.second.first != it.second.second){
                for(int j=it.second.first+1;j<it.second.second;j++){
                    set1.insert(s[j]);
                }
                cnt+=set1.size();
            }           
        }

        return cnt;
    }
};
