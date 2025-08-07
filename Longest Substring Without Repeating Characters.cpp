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


//Revision

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, maxi=0;
        int n=s.size();
        unordered_map<char,int> mpp;
        while(r<n){
            if(mpp.find(s[r])!=mpp.end()){
                while(mpp[s[r]]!=0 && l<r){
                    mpp[s[l]]--;
                    l++;
                }
            }
            mpp[s[r]]++; 
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};
