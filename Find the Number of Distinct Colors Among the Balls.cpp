class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball_color;
        unordered_map<int, int> color_freq;
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int ball = queries[i][0];
            int color = queries[i][1];
            if(ball_color.find(ball)!=ball_color.end()){
                int prevcolor = ball_color[ball];
                color_freq[prevcolor]--;
                if(color_freq[prevcolor]==0){
                    color_freq.erase(prevcolor);
                }
            }
            
            ball_color[ball] = color;
            
            color_freq[color]++;

            ans.push_back(color_freq.size());
        }
        return ans;
    }
};
