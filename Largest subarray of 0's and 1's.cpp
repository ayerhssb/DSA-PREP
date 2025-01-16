class Solution {
  public:
    int maxLen(vector<int> &arr) {
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                arr[i]=-1;
            }
        }
        int len=0,sum=0;
        unordered_map<int,int> mp;
        
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==0){
                len=max(len,i+1);
            }
            if(mp.find(sum)!=mp.end()){
                len=max(len,i-mp[sum]);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }
        
        return len;
    }
};
