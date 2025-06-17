class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // int a= nums[0];
        // for(int i=1; i<nums.size(); i++){
        //     a = a^nums[i];
        // }
        // // cout << int(0^6^6);
        // return a;
        int n= nums.size();
        if(n==1){return nums[0];}
        int low=0, high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if((mid==nums.size()-1 && nums[mid]!=nums[mid-1])|| (mid==0 && nums[mid]!=nums[mid+1])){return nums[mid];}
            if(mid+1 < n && mid-1>0 && nums[mid+1]!=nums[mid]&&nums[mid-1]!=nums[mid]){return nums[mid];}
            if(mid%2==0 && nums[mid]==nums[mid+1] || (mid%2!=0 &&nums[mid]==nums[mid-1])){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;

    }
};
