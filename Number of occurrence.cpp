class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<target) continue;
            if(arr[i]>target) break;
            mp[target]++;
            
        }
        return mp[target];
    }
};
