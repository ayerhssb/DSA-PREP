class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    
    // bool comp(const static pair<int, int> a, const pair<int, int> b) {
    //       return a.second < b.second; // Ascending order by the second element
    // }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n=start.size();
        vector<pair<int,int>> meet;
        for(int i=0;i<n;i++){
            meet.push_back({start[i], end[i]});
        }
        // sort(meet.begin(),meet.end(),comp);
        sort(meet.begin(), meet.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });
        int cnt=0, lastEnd = -1;
        for(int i=0;i<n;i++){
            if(meet[i].first>lastEnd){
                cnt++;
                lastEnd = meet[i].second;
            }
        }
        return cnt;
    }
};
