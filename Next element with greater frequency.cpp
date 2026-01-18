class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> ans(n,-1);
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&& mpp[arr[i]]>mpp[arr[st.top()]]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
