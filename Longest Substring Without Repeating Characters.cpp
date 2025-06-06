class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 1) {
            return 1;
        }
        int n = s.size();
        int maxi = 0;
        unordered_map<int, int> mpp;
        int left = 0, right = left + 1;
        mpp[s[0]] = 0;
        while (right < n) {
            if (mpp.find(s[right]) != mpp.end() && mpp[s[right]] >= left) {
                left = mpp[s[right]] + 1;
            }

            mpp[s[right]] = right;

            maxi = max(maxi, right - left + 1);
            right++;
        }

        return maxi;
    }
};
