//rev:

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        unordered_map<int,int> mpp;
        int n=arr.size(),cnt=0;
        for(auto it:arr){
            mpp[it]++;
        }
        for(int i=1;i<=arr[n-1];i++){
            if(mpp.find(i)==mpp.end()){
                cnt++;
            }
            if(cnt==k){
                return i;
            }
        }
        // return arr[n-1]+k;        
        return arr[n-1]+k-cnt;
    }
};


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0, high = arr.size()-1;
        int ans;
        if(arr.size()==1){
            if(k<arr[0]){
                return k;
            }
            else{
                k+1;
            }
        } 
        while(low<=high){
            int mid = (low+high)/2;
            
            if((arr[mid]-mid-1)<k) low = mid+1;
            else{
                high = mid-1;
            }
            // if(low>arr.size()-1) return arr[arr.size()-1]-arr[0]+1+k;
            // if(high < 0) return low+k;
            // ans = low+k;
        }
         
        return k+high+1;
    }
};
