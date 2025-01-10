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
