//rev:

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> mpp;
        vector<int> ans;
        for(int i=0;i<k;i++){
            mpp[arr[i]]++;
        }
        int l=0;
        ans.push_back(mpp.size());
        for(int i=k;i<arr.size();i++){
            mpp[arr[i]]++;
            mpp[arr[l]]--;
            if(mpp[arr[l]]==0){mpp.erase(arr[l]);}
            ans.push_back(mpp.size());
            l++;
        }
        return ans;
    }
};


class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        vector<int> ans;
        int i=0,j=k-1;
        while(i<=j && j<arr.size()){
            unordered_set<int> st;
            for(int k=i;k<=j;k++){
                st.insert(arr[k]);
            }
            ans.push_back(st.size());
            i++;
            j++;
        }
        
        return ans;
    }
};
