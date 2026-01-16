class Solution {
  public:
    int minMen(vector<int>& arr) {
        int ans=0,maxi=-1,n=arr.size();
        vector<pair<int,int>> range;
        for(int i=0;i<n;i++){
            if(arr[i]!=-1){
                int low = max(0,i-arr[i]);
                int high= min(n-1,i+arr[i]);
                range.push_back({low,high});
            }
        }
        if(range.empty()){return -1;}
        sort(range.begin(),range.end(),[&](const pair<int,int> &a, const pair<int,int> &b){
            if(a.first==b.first){
                return a.second>b.second;
            }
            return a.first<b.first;
        });
        
        int i=0,len=range.size();
        while(maxi<n-1){
            if(i>=len){return -1;}
            if(i<len && range[i].first>maxi+1){return -1;}
            int rightmost=maxi;
            while(i<len && range[i].first<=maxi+1){
                rightmost=max(rightmost,range[i].second);i++;
            }
            ans++;maxi=rightmost;
        }
        return ans;
    }
};
