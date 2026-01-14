class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n=arr.size(),ans=0;
        int p=0,t=0;
        while(p<n&&t<n){
            while(p<n && arr[p]!='P'){p++;}
            while(t<n && arr[t]!='T'){t++;}
            if(p<n && t<n && abs(p-t)<=k){
                ans++;
                p++;t++;
            }
            else if(t<n && p>t){
                t++;
            }
            else{
                p++;
            }
        }
        return ans;
    }
};
