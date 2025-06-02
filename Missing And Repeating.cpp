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
