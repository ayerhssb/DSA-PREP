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
