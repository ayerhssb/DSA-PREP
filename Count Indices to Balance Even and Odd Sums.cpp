class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        int n=arr.size();
        int tOddSum=0, tEvenSum=0, cnt=0;
        vector<int> prefix(n);
        for(int i=0;i<arr.size();i++){
            if(i>1){
                prefix[i]=arr[i]+prefix[i-2];
            }
            else{
                prefix[i]=arr[i];
            }
        }
        if(n%2){tOddSum=prefix[n-2];tEvenSum=prefix[n-1];}
        else{tOddSum=prefix[n-1];tEvenSum=prefix[n-2];}
        for(int i=0;i<arr.size();i++){
            if(i==0){
                int oddSum=tEvenSum-prefix[i];
                int evenSum=tOddSum;
                if(oddSum==evenSum){cnt++;}
            }
            else if(i==1){
                int oddSum=tEvenSum-prefix[i-1];
                int evenSum=prefix[i-1]+tOddSum-prefix[i];
                if(oddSum==evenSum){cnt++;}
            }
            else{
                if(i%2){
                    int oddSum=prefix[i-2]+tEvenSum-prefix[i-1];
                    int evenSum=prefix[i-1]+tOddSum-prefix[i];
                    if(oddSum==evenSum){cnt++;}
                }
                else{
                    int evenSum=prefix[i-2]+tOddSum-prefix[i-1];
                    int oddSum=prefix[i-1]+tEvenSum-prefix[i];
                    if(oddSum==evenSum){cnt++;}
                }
            }
        }
        return cnt;
    }
};
