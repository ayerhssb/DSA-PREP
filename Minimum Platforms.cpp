class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n=arr.size();
        int a=0,d=0, cnt=0;
        int maxi=-1;
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        while(a<n && d<n){
            
            if(arr[a]<=dep[d]){
                cnt++;
                a++;
            }else{
                cnt--;
                d++;
            }
            maxi=max(maxi,cnt);
        }
        
        return maxi;
    }
};
