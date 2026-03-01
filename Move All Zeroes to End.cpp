//runtime error:

// class Solution {
//   public:
//     void pushZerosToEnd(vector<int>& arr) {
//         int i=0,j=0,n=arr.size();
//         while(arr[i]!=0){
//             i++;j++;
//         }
//         while(j<n && i<n){
//             while(arr[j]==0){
//                 j++;
//             }
//             if(j>=n){return;}
//             swap(arr[i],arr[j]);
//             i++;
//         }
//     }
// };


//optimal 
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int j=0,n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                swap(arr[i],arr[j]);
                j++;
            }
        }
    }
};
