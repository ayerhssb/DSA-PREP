class Solution {
  public:
    void segregate0and1(vector<int> &arr) {;
        int n=arr.size();
        int l=0, h=n-1;
        while(l<=h){
            if(arr[l]==0){l++;}
            else{
                swap(arr[h],arr[l]);
                h--;
            }
        }
    }
};
