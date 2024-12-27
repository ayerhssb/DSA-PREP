class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int i=0,j=arr.size()-1;
        while(i<j){
            if((arr[i]+arr[j])==target){
                return true;
            }
            else if((arr[i]+arr[j])>target){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};