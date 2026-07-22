#include <bits/stdc++.h>
using namespace std;

class solution {
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums2[j]>nums2[i]){
                    mpp[nums2[i]]=nums2[j];
                    // flag=1;
                    break;
                }
            }
            // if(flag==0){mpp[nums2[i]]=-1;}
        }
        
        for(int i=0;i<nums1.size();i++){
            if(mpp.find(nums1[i])==mpp.end()){
                ans.push_back(-1);continue;
            }
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};

// ---------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    vector<int> nextGreaterElement(vector<int> arr) {
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n);
        // st.psuh(arr[arr.size()-1]);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(!st.empty() && st.top()>arr[i]){
                ans[i] = st.top();
                st.push(arr[i]);
            }
            else{
                ans[i]=-1;
                st.push(arr[i]);
            }
        }
        return ans;
    }
};
