class Solution {
  public:
  
    int binsearch(vector<int>& arr, int low, int high, int x){
        int index=-1;
        if(low>high){
            return -1;
        }
        
        while(low<=high){
            int mid =(low+high)/2;
            if(arr[mid]<=x){
                index=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return index;
        
    }

    int findFloor(vector<int>& arr, int x) {
        return binsearch(arr,0,arr.size()-1,x);
    }
};
