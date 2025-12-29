class Solution {
  public:
  
    pair<int,int> El(vector<int> &arr, int n){
        int sum=0,mini=INT_MAX;
        for(auto it:arr){
            sum+=it;
            mini=min(mini,it);
        }
        int el1 = mini*(n * (n+1)/2);
        int el2= (n/sum+1)* (arr.size());
        return {el1,el2};
    }
    
    bool canMake(int mid, vector<int> &ranks, int n){
        int totalDonut=0;
        for(int i=0;i<ranks.size();i++){
            int k=1,donut=0,time=0;
            while(time<=mid){
                time += k*ranks[i];
                if(time>mid){break;}
                donut++;
                k++;
            }
            totalDonut+=donut;
            if(totalDonut>=n){return true;}
        }
        return false;
    }
    int minTime(vector<int>& ranks, int n) {
        int l=0, h=El(ranks,n).first,ans=0;
        while(l<=h){
            int mid = (h+l)>>1;
            if(canMake(mid,ranks,n)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
