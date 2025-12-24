class Solution {
  public:
    int upperBound(int num, vector<int> &arr){
        int l=0,h=arr.size()-1;
        while(l<=h){
            int mid=(l+h)>>1;
            if(arr[mid]==num){
                int j=mid+1;
                while(j<arr.size() && arr[j]==arr[mid]){
                    j++;
                }
                // if(j==mid+1){return mid;}
                return j-1;
            }
            if(arr[mid]>num){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return h;
    }
    int lowerBound(int num, vector<int> &arr){
        int l=0,h=arr.size()-1;
        while(l<=h){
            int mid=(l+h)>>1;
            if(arr[mid] ==num){
                int j=mid-1;
                while(j>=0 && arr[j]==arr[mid]){
                    j--;
                }
                // if(j==mid-1){return mid;}
                return j+1;
            }
            if(arr[mid]>num){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        sort(arr.begin(),arr.end());
        vector<int> res;
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0], h=queries[i][1];
            int ans = upperBound(h,arr) - lowerBound(l,arr)+1;
            res.push_back(ans);
        }
        return res;
    }
};
