//rev::
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0, ans=INT_MIN, m=k;
        while(r<nums.size()){
            if(m==0 && nums[r]==0){
                while(m==0){
                    if(nums[l]==0){m++;l++;break;}
                    l++;
                }
            }
            if(nums[r]==0){m--;}
            ans=max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};



//revision:
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,cnt=0,maxi=0;
        while(r<nums.size()){
            if(k==0&&nums[r]==0){
                while(nums[l]!=0){
                    l++;
                }
                l++;
                r++;
            }
            else if(nums[r]==0){k--;r++;}
            else{
                r++;
            }
            cnt=r-l;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};

#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int findMaxOnes(vector<int>& arr, int k) {
        int l=0,r=0, zero=0;
        int n=arr.size(), maxLen=0;
        while(r<n){
            if(arr[r]==0){
                zero++;
            }
            while(zero>k){
                if(arr[l]==0){
                    zero--;
                }
                l++;
            }
            int len = r-l+1;
            maxLen = max(maxLen,len);
            r++;
        }
        return maxLen;
    }
};
