class Solution {
public:
    bool comp(int a,int b){
        return a>b;
    }
    int minimumPushes(string word) {
        unordered_map<char,int> mpp;
        vector<int> arr(26,0);
        for(int i=0;i<word.size();i++){
            arr[word[i]-'a']++;
        }
        sort(arr.begin(),arr.end(),[](int a, int b){return a>b;});
        int ans=0;
        for(int i=0;i<26;i++){
            ans += (i/8 +1)*arr[i];
        }

        return ans;
    }
};
