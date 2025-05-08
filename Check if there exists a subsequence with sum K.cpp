class Solution {
  public:
  
    bool helper(int n, int ind, vector<int> arr, int k, int sum){
        if(sum==k){
            return true;
        }
        if(sum>k){
            return false;
        }
        if(sum<k && ind==n){return false;}
        return (helper(n, ind+1, arr, k, sum+arr[ind]) || helper(n, ind+1, arr, k, sum));
        
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        if(helper(n, 0, arr, k, 0)==true){return true;}
        
        return false;
    }
};
