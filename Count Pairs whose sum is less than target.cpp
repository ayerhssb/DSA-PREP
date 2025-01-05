class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        sort(arr.begin(),arr.end());
        int l=0,h=arr.size()-1, cnt=0;
        while(l<h){
            int sum =arr[l]+arr[h];
            if(sum>=target){
                h--;
            }
            else{
                cnt= cnt+h-l;
                l++;
            }
        }
        return cnt;
    }
};
