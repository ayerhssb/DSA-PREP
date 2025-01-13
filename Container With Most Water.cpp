class Solution {

  public:
    int maxWater(vector<int> &arr) {
        int low=0, high=arr.size()-1;
        int maxvol=0;
        while(low<high){
            int mini= min(arr[low],arr[high]);
            // int maxi= max(arr[low],arr[high]);
            int vol= (high-low)*(mini);
            if(mini==arr[low]){
                low++;
            }
            else{
                high--;
            }
            maxvol = max(vol, maxvol);
        }
        
        return maxvol;
    }
};
