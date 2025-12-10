//rev

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        vector<int> ans(2);
        unordered_map<int,int> mpp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(mpp.find(arr[i])!=mpp.end()){
                ans[0]=arr[i];
            }
            mpp[arr[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(mpp.find(i)==mpp.end()){
                ans[1]=i;
                break;
            }
        }
        return ans;
    }
};

//initial
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n=arr.size();
        vector<int> mpp(n,0);
        int repeating=-1, missing=-1;
        
        for(int i=0;i<n;i++){
            mpp[arr[i]-1]++;
        }
        for(int i=0;i<n;i++){
            if(mpp[i] == 2){
                repeating=i+1;
            }
            if(mpp[i]==0){
                missing=i+1;
            }
            if(repeating!=-1 && missing != -1){
                break;
            }
        }
        return {repeating, missing};
    }
};
