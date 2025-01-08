class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        int cnt=0;
        sort(arr.begin(),arr.end());
        for(int i=arr.size()-1;i>=2;i--){
            int j=0,k=i-1;
            while(j<k){
                int sum = arr[k]+arr[j];
                if(sum>arr[i]){
                    cnt+= (k-j);
                    k--;
                }
                else {j++;}
            }
        }
        return cnt;
    }
};
