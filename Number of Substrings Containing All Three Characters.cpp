//revision:

class Solution {
public:
    //use of map instead of vector && use of while loop inside...to check for duplicacy
    int numberOfSubstrings(string s) {
        int n=s.size();
        int l=0,r=0,ans=0;
        // vector<int> arr(3,0);
        unordered_map<char,int> mpp;
        while(r<n){
            mpp[s[r]]++;
            while(mpp.size()==3){
                ans+=(n-r);
                mpp[s[l]]--;
                if(mpp[s[l]]==0){mpp.erase(s[l]);}
                l++;
            }
            r++;
        }
        return ans;
    }
};



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
