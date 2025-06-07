class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
        vector<int> curr= {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        vector<int> list;
        int p=curr.size()-1;
        while(p>=0){
            if(N/curr[p]==0){p--;continue;}
            int n=N/curr[p];
            for(int i=0;i<n;i++){
                list.push_back(curr[p]);
            }
            N=N%curr[p];
            p--;
        }
        return list;
    }
};
