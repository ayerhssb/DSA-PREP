class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int n) {
        unordered_map<int, long long> mpp;
        long long days = 0;
        for (int i = 0; i < tasks.size(); i++) {
            days++;
            if (mpp.find(tasks[i]) != mpp.end()) {
                days = mpp[tasks[i]] = max(mpp[tasks[i]] + n+1, days);
            } else {
                mpp[tasks[i]] = days;
            }
            // cout<<days<<endl;
        }
        return days;
    }
};
