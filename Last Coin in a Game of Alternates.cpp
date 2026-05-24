class Solution {
  public:
    int coin(vector<int>& arr) {
        int n= arr.size();
        if(n==1){return arr[0];}
        int l=0,r=n-1;
        
        while(l<r){
            if(arr[l]>=arr[r]){
                l++;
            }
            else{
                r--;
            }
        }
        
        return arr[l];
    }
};
