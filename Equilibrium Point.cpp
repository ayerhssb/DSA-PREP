class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        
        int total=0;
        vector<int> sum_arr;
        for(int i=0;i<arr.size();i++){
            total+=arr[i];
            sum_arr.push_back(total);
        }
        
        for(int i=1;i<arr.size();i++){
            int left_sum = sum_arr[i] - arr[i];
            int right_sum = total - sum_arr[i];
            if(left_sum == right_sum){
                return i;
            }
        }
        return -1;
    }
};
