class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int> mpp;
        int n, ans=0;
        for(int i=0;i<dominoes.size();i++){
            sort(dominoes[i].begin(), dominoes[i].end());
            int num = 10* dominoes[i][0] + dominoes[i][1];
            
                mpp[num]++;
            
        }
        for(auto it: mpp){
            if(it.second >1){
                n= it.second;
                ans += ((n-1)*n)/2;
            }
        }
        return ans;
        
    }
};
