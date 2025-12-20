//O(logN) complexity
//Binary search
class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        int ans=arr.size();
        int l=0, h=arr.size()-1;
        while(l<=h){
            int mid=(l+h)>>1;
            if(arr[mid]==k){return mid;}
            if(arr[mid]<k){l=mid+1;}
            else{
                h=mid-1;
            }
        }
        return l;
    }
};


//Brute approach
class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        int ans=arr.size();
        
        for(int i=0;i<arr.size();i++){
             if(k<=arr[i]){
                 return i;
             }
         }
         return ans;
    }
};
