class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
        vector<int> res;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        int i=0;
        while(i<k){
            pq.push({arr[i][0],{i,0}});
            i++;
        }
        while(!pq.empty()){
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            int val = pq.top().first;
            pq.pop();
            res.push_back(val);
            if(col+1<k)pq.push({arr[row][col+1],{row,col+1}});
        }
        
        return res;
        
    }
};
