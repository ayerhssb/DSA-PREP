//revision::

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(nums[mid]==target){return mid;}
            if(nums[l]<=nums[mid]){
                if(target<nums[mid]&&target>=nums[l]){
                    r=mid-1;
                }else{l=mid+1;}
            }else{
                if(target>nums[mid]&&target<=nums[r]){l=mid+1;}else{r=mid-1;}
            }
        }
        return -1;
    }
};

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int low=0, high=arr.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==key) return mid;
            if(arr[mid]>=arr[low]){
                if(arr[mid]>key && (arr[low]<=key)){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            } 
            else{
                if(arr[mid]<key && (arr[high]>=key)){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};
