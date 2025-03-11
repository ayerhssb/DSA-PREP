class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        int left = 0, right=0;
        unordered_map<char,int> mpp = {{'a',0}, {'b',0}, {'c', 0}};

        for(int right=0;right<s.size();right++){
            mpp[s[right]]++;

            while(mpp['a']>0 && mpp['b']>0 && mpp['c']>0){
                count += s.size() - right;
                mpp[s[left]]--;

                left++;
            }
        }
        return count;

    }
};
