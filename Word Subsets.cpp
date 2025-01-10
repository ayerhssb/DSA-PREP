class Solution {
public:
    bool isUniversal(vector<int>& charnum, vector<int>& max_freq){
        for(int i=0;i<26;i++){
            if(charnum[i]<max_freq[i]){
                return false;
            }
        }
        return true;
    }
    void find_max_freq(vector<int>& freq,vector<int>& max_freq){
        for(int i=0;i<26;i++){
            max_freq[i] = max(max_freq[i], freq[i]);
        }
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // unordered_map<char,int> mp;
        vector<string> ans;
        vector<int> max_freq(26,0);
        for(int i=0;i<words2.size();i++){
            vector<int> freq(26,0);
            for(int j=0;j<words2[i].size();j++){
                freq[words2[i][j]-'a']++;
            }
            find_max_freq(freq, max_freq);
        }

        
        
        for(int i=0;i<words1.size();i++){
            vector<int> charnum(26,0);
            for(int j=0;j<words1[i].size();j++){
                charnum[words1[i][j]-'a']++;
            }
            if(isUniversal(charnum,max_freq)){
                ans.push_back(words1[i]);
            }
        }

        return ans;
    }
};
