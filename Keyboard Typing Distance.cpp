#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    int calculateTypingDistance(string text) {
        string str1 = "qwertyuiop", str2="asdfghjkl", str3="zxcvbnm";
        vector<pair<int,int>> arr(26);
        int dist=0, prev_row, prev_col, curr_col, curr_row;
        for(int i=0;i<str1.size();i++){
            arr[str1[i]-'a'] = {0,i};
        }
        for(int i=0;i<str2.size();i++){
            arr[str2[i]-'a'] = {1,i};
        }
        for(int i=0;i<str3.size();i++){
            arr[str3[i]-'a'] = {2,i};
        }
        //print the arr vector
        // for(int i=0;i<26;i++){
        //     cout<<char(i+'a')<<" : "<<arr[i].first<<" "<<arr[i].second<<"\n";
        // }
        char ch= 'a';
        prev_row = arr[ch-'a'].first;
        prev_col = arr[ch-'a'].second;
        for(int i=0;i<text.size();i++){
            curr_row = arr[text[i]-'a'].first;
            curr_col = arr[text[i]-'a'].second;
            dist += (abs(curr_row-prev_row) + abs(prev_col-curr_col));
            
            // cout<< "dist: "<<dist<<"curr_row: "<<curr_row<<"curr_col: "<<curr_col<<"prev_row: "<<prev_row<<"prev_col: "<<prev_col<<"\n";
            prev_col=curr_col; prev_row=curr_row;
        }
        return dist;
    }
};
