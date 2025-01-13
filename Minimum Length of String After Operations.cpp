class Solution {
public:
    int minimumLength(string s) {
        // unordered_map<char,int> mp;
        vector<int> freq(26,0);
        int cnt= 0;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
            // cnt++;
        }

        for(auto it:freq){
            if(it==0){
                continue;
            }
            else if(it%2 ==0){
                cnt+=2;
            }
            else{
                cnt+=1;
            }
        }
        return cnt;
    }
};
