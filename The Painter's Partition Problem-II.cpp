// User function template for C++

class Solution {
  public:
  pair<int,int> maxEl(vector<int> &arr){
        int sum=0,maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
            sum+=arr[i];
        }
        return {maxi, sum};
    }
    int helper(vector<int> &arr, int k, int mid){
        int students=1, sumPages=0;
        for(int i=0;i<arr.size();i++){
            if(sumPages+arr[i]<=mid){
                sumPages+=arr[i];
            }
            else{
                sumPages=arr[i];
                students++;
            }
        }
        
        return students;
    }
    int minTime(vector<int>& arr, int k) {
        // if(k>arr.size()){
        //     return -1;
        // }
        int low=maxEl(arr).first, high=maxEl(arr).second;
        while(low<=high){
            int mid=(low+high)>>1;
            // if(helper(arr, k, mid)==k){return mid;}
            if(helper(arr, k, mid)>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
