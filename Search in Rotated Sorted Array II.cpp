class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int low=0,high=nums.size()-1;
       while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){return true;}
        else if(nums[mid]==nums[low] && nums[mid]==nums[high]){low++; high--;}
        else if(nums[mid]>=nums[low] ){
            if(target<=nums[mid] && target>=nums[low]){high=mid-1;}
            else{low=mid+1;}
        }
        else{
            if(target<=nums[high] && target>=nums[mid]){low=mid+1;}
            else{high=mid-1;}
        }
       }

       return false;
    }
};

//revision 1:

#include <bits/stdc++.h>
using namespace std;

class solution{
public:
    bool searchRotatedSorted(int arr[], int n, int k){
        int low=0,high=n-1;
        while(low<=high){
            int mid = (low+high)>>1;
            if(arr[mid]==k){return 1;}
            else if(arr[low]>=arr[high] && arr[mid]<=arr[low]){
                if(k>arr[mid] && k<arr[high]){
                    low=mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            else if(arr[low]>=arr[high] && arr[mid]>=arr[low]){
                if(k<arr[mid] && k>arr[low]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(k>arr[mid]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return 0;
    }
};
