#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAttendAllMeetings(vector<vector<int>>& schedule) {
        sort(schedule.begin(),schedule.end());
        // for(int i=0;i<schedule.size();i++){
        //     cout<< schedule[i][0]<<" "<< schedule[i][1]<<endl;
        // }
        for(int i=0;i<schedule.size()-1;i++){
            if(schedule[i][1]>schedule[i+1][0]){return false;}
        }
        return true;
    }
};
