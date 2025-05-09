class Solution {
  public:
  
    void helper(int ind, int sum,int n, vector<int>& ans, vector<int>& arr){
        if(ind==n){ans.push_back(sum);return;}
        
        helper(ind+1, sum + arr[ind],n, ans,arr);
        helper(ind+1,sum,n, ans,arr);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> ans;
        int n=arr.size();
        helper(0,0,n,ans,arr);
        return ans;
    }
};
