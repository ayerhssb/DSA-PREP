class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n=words.size();
        string ans;
        for(int i=0;i<n;i++){
            int sum=0;
            for(auto it:words[i]){
                sum+= weights[it-'a'];
            }
            int w = 25 - (sum%26);

            ans.push_back(w+'a');
        }
        return ans;
    }
};
