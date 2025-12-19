//2nd time:

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end(),[](const vector<int> &a, const vector<int> &b){
            return a[0]<b[0];
        });
        int start=arr[0][0], end=arr[0][1];
        for(int i=0;i<arr.size()-1;i++){
            if(end>=arr[i+1][0]){
                end=max(end,arr[i+1][1]);
            }
            else{
                ans.push_back({start,end});
                start=arr[i+1][0];
                end=arr[i+1][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0;i<n;i++){
            if(ans.empty()|| arr[i][0]>ans.back()[1]){
                ans.push_back(arr[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1],arr[i][1]);
            }
        }
        return ans;
        
    }
};
