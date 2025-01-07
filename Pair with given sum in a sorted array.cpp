class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        unordered_map<int, int> mp;
        int cnt=0;
        
        for(int i=0;i<arr.size();i++){
            int k=target-arr[i];
            if(mp.find(k)!=mp.end()){
                cnt+=mp[k];
            }
            mp[arr[i]]++;
        }
        return cnt;
        

        //TLE
        // int low=0,high=arr.size()-1, cnt=0;
        // while(low<high){
        //     if(arr[low]+arr[high]==target){
        //         if(arr[low]==arr[high]){
        //             int n=high-low+1;
        //             cnt+= ((n-1)*n)/2;
        //         }
        //         else{
        //             int cnt_high=0, cnt_low=0;
        //             int t1=arr[low], t2=arr[high];
        //                 while(t1==arr[low] && low<arr.size()){
        //                     cnt_low++;
        //                     low++;
        //                 }
        //                 while(t2==arr[high] && high>=0 ){
        //                     cnt_high++;
        //                     high--;
        //                 }
                        
        //             // if(cnt_low==1) low++;
        //             // if(cnt_high==1) high--;
        //             cnt+= (cnt_high * cnt_low);
        //         }
                
        //     }
        //     else if(arr[low]+arr[high]>target){
        //         high--;
        //     }
        //     else{
        //         low++;
        //     }
        // }
        
        // return cnt;
    }
};
