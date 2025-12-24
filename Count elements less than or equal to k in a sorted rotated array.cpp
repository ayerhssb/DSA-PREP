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
    int countLessEqual(vector<int>& arr, int x) {
        int ans=0;
        sort(arr.begin(),arr.end());
        ans=upperBound(x,arr) + 1;
        return ans;
    }
};
