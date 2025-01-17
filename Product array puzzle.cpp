class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        //BRUTE FORCE APPROACH
        // int totalproduct =1,cnt_zero=0;
        // vector<int> res;
        // for(int it: arr){
        //     if(it==0){cnt_zero++; continue;}
        //     totalproduct *= it;
        // }
        
        // if(cnt_zero>=2){
        //     for(int i=0;i<arr.size();i++){
        //         res.push_back(0);
        //     }
        //     return res;
        // }
        
        // for(int i=0;i<arr.size();i++){
        //     if(cnt_zero>0 && arr[i]!=0){
        //         res.push_back(0);
        //     }
        //     else if(cnt_zero>0 && arr[i]==0){
        //         res.push_back(totalproduct);
        //     }
        //     else{
        //         int ans = totalproduct/arr[i];
        //         res.push_back(ans);
        //     }
        // }
        
        // return res;
        
        
        //BETTER APPROACH
        // vector<int> res,left,right;
        //Using left and right rray (space complexity -> O(N) and time -> O(N))
        
        
        //OPTIMAL APPROACH (TIME->O(N), SPACE->O(1))
        vector<int> res;
        int prod=1,n=arr.size();
        
        for(int i=0;i<n;i++){
            prod*=arr[i];
            res.push_back(prod);
            
        }
        prod=1;
        for(int i=n-1;i>=1;i--){
            res[i]= prod*res[i-1];
            prod=prod*arr[i];
        }
        res[0]=prod;
        
        
        return res;
        
    }
};
