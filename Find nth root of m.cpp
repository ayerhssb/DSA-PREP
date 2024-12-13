lass Solution {
  public:
  int fn(int mid, int n){
      return pow(mid,n);
  }
    int nthRoot(int n, int m) {
        if(n==1)return m;
        int low=1,high=m;
        while(low<=high){
            int mid=(low+high)/2;
            if(fn(mid,n)==m)return mid;
            if(fn(mid,n)>m){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1; 
        
    }
};
