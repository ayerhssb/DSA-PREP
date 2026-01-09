class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n=arr.size(),ans=0;
        // set<int> st;
        unordered_map<int,int> mpp;
        int l=0,r=0;
        while(r<n){
            // st.insert(arr[r]);
            mpp[arr[r]]++;
            if(mpp.size()<=k){
                int len= r-l;
                ans+=len;
                r++;
            }
            else{
                while(mpp.size()>k){
                    if(mpp.find(arr[l])!=mpp.end()){
                        mpp[arr[l]]--;
                    }
                    if(mpp[arr[l]]==0){
                        mpp.erase(arr[l]);
                    }
                    l++;
                }
                int len= r-l;
                ans+=len;
                r++;
            }
        }
        // if(l==0&&r==n){return (((n-1)*(n))/2)+n;}
        return ans+n;
    }
};
