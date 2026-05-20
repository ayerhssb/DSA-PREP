typedef long long ll;

class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        
        unordered_set<ll> mpp;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0 && target==0){return true;}
            if(arr[i]==0){
                mpp.insert(0);continue;
            }
            if(target%arr[i]==0){
                ll div = target/(ll)arr[i];
                if(mpp.find(div)!=mpp.end()){
                    return true;
                }
            }
            mpp.insert((ll)arr[i]);
        }
        return false;
    }
};
