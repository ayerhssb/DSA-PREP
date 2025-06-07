class Solution {
  public:
    long long solve(vector<int>& bt) {
        int waitTime=0;
        int t=0;
        sort(bt.begin(),bt.end());
        for(int i=0;i<bt.size();i++){
            waitTime+=t;
            t+=bt[i];  
        }
        return waitTime/bt.size();
    }
};
