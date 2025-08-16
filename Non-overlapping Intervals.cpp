//revision (leetcode):

class Solution {
public:
    static bool comp(const vector<int>&a, const vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int prev=0,n=intervals.size(), ans=0;
        for(int i=1;i<n;i++){
            if(intervals[prev][1]>intervals[i][0]){
                ans++;
            }
            else{
                prev=i;
            }
        }
        return ans;
    }
};

class Solution {
  public:
    static bool sortcol(const vector<int> &v1,const vector<int> &v2) { 
        return v1[1] < v2[1]; 
    } 
    int minRemoval(vector<vector<int>> &intervals) {
        int cnt=0;
        sort(intervals.begin(), intervals.end(), sortcol);
        // sortcol(intervals.begin(), intervals.end());
        if(intervals.size()==1)return 0;
        int lastendtime = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]>=lastendtime){
                lastendtime=intervals[i][1];
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};
