class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x=0;
        int n=nums1.size(),m=nums2.size();
        if((n%2==0&& m%2!=0)){
            for(auto it:nums1){
                x = x^it;
            }
        }
        else if(n%2!=0&& m%2==0){
            for(auto it:nums2){
                x = x^it;
            }
        }
        else if(n%2!=0 && m%2 !=0){
            for(auto it:nums1){
                x = x^it;
            }
            for(auto it:nums2){
                x = x^it;
            }
        }
        else{
            return 0;
        }
        return x;
    }
};
