#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    int noofwords(string str){
        int cnt=0;
        stringstream ss(str);
        string word;
        while(ss>> word){cnt++;}
        return cnt;
    }
    string userWithMostWords(int n, vector<string>& posts, vector<string>& usernames) {
        string ans=""; int maxi=0;
        map<string, int> mpp;
        for(int i=0;i<n;i++){
            int noofwords1 =  noofwords(posts[i]);
            mpp[usernames[i]] += noofwords1;
        }
        for(auto it:mpp){
            bool bigname = lexicographical_compare(ans.begin(), ans.end(), it.first.begin(), it.first.end());
            if(it.second>maxi){
                maxi=it.second;
                ans=it.first;
            }else if(it.second==maxi && bigname){
                ans=it.first;
            }
        }
        return ans;
    }
};
