//revision

#include <bits/stdc++.h>
using namespace std;

class solution{
public:
    int conferenceRoomBooking(vector<int>& begin, vector<int>& finish) {
        int ans=1;
        vector<pair<int, int>> time;
        for(int i=0;i<begin.size();i++){
            time.push_back({begin[i], finish[i]});
        }
        sort(time.begin(), time.end(), [&](const pair<int,int> a, const pair<int,int> b){
            if(a.second==b.second){
                return a.first<b.first;
            }
            return a.second<b.second;
        });
        int i=1;
        int lastend=time[0].second;
        while(i<begin.size()){
            if(time[i].first > lastend){
                ans++;
                lastend=time[i].second;
            }
            i++;
        }
        return ans;
    }
};


//---------------------------------------------------------------------------------------

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
