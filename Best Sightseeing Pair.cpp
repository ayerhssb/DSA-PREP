class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxscore=0;
        int first = values[0]+0;
        for(int j=1;j<values.size();j++){
            int second = values[j]-j;
            maxscore = max(maxscore, second+first);
            first = max(first, values[j]+j);
        }

        return maxscore;
    }
};
