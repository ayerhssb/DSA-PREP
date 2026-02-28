class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        vector<int> ans(2,0);
        int n=arr1.size(), m=arr2.size();
        int l=0,r=m-1;
        int diff=INT_MAX;
        while(l<n&&r>=0){
            int sum=arr1[l]+arr2[r];
            int currdiff= abs(sum-x);
            if(currdiff<diff){
                diff=currdiff;
                ans[0]=arr1[l];
                ans[1]=arr2[r];
            }
            if(sum>x){
                r--;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};
