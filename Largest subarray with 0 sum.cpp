class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int preSum=0;
        int maxi=0;
        unordered_map<int,int> mpp;
        for(int i=0;i<arr.size();i++){
            preSum+=arr[i];
            if(preSum==0){
                maxi=i+1;
            }
            if(mpp.find(preSum)!=mpp.end()){
                maxi=max(maxi,i-mpp[preSum]);
            }
            else{mpp[preSum]=i;}
        }
        return maxi;
    }
};
