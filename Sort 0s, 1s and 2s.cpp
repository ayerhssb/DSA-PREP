//rev:

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int l=0,m=0,h=arr.size()-1;
        while(m<=h){
            if(arr[m]==0){
                swap(arr[l],arr[m]);
                l++;m++;
            }
            else if(arr[m]==1){
                m++;
            }
            else{
                swap(arr[h],arr[m]);
                h--;
            }
        }
    }
};

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int low=0, mid=0,high=arr.size()-1;
        while(mid<=high){
            if(arr[mid]==0) {swap(arr[mid],arr[low]); mid++; low++;}
            else if(arr[mid]==1) mid++;
            else {
                swap(arr[mid],arr[high]);
                high--;
            }
        }
    }
};
