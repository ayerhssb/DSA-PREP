class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(), greater<>());
        int n=cost.size(), ans=0;
        for(int i=1;i<=n;i++){
            if(i%3==1 || i%3==2){
                ans+=cost[i-1];
            }
        }
        
        return ans;
    }
};
