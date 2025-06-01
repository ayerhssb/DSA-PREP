class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        vector<int> prev;
        ans.push_back({1});
        if(n==1){
            return ans;
        }
        
        
        for(int i=1;i<n;i++){
            vector<int> list(i+1);
            list[0]=1;
            list[i]=1;
            for(int j=1;j<i;j++){
                list[j] = prev[j-1] + prev[j];
            }
            ans.push_back(list);
            prev = list;
        }
        return ans;
    }
};
