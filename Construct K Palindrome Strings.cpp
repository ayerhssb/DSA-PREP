class Solution {
public:
    bool canConstruct(string s, int k) {
        // sort(s.begin(),s.end());
        if(s.size()<k){
            return false;
        }
        int oddcnt=0;
        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        for(auto it:mp){
            if((it.second) %2){
                oddcnt++;
            }
        }
        // cout<< oddcnt<<endl;
        if(oddcnt <=k){
            return true;
        }
        return false;
    }
};
