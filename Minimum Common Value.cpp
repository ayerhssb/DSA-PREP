class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int left=0, right=0;
        int n=nums2.size(), m=nums1.size();
        while(left<m&&right<n){
            if(nums1[left]==nums2[right]){return nums1[left];}
            else if(nums1[left]<nums2[right]){left++;}
            else{
                right++;
            }
        }
        return -1;
    }
};
