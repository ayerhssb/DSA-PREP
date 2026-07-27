#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    bool validAnagram(string s1, string s2) {
        if(s1.size()!=s2.size()){return false;}
        vector<int> arr(26, 0);
        for(int i=0;i<s1.size();i++){
            arr[s1[i]-'a']+=1;
            arr[s2[i]-'a']-=1;
        }
        
        for(int i=0;i<26;i++){
            if(arr[i]!=0){
                return false;
            }
        }
        return true;
    }

};


// --------------------------------------------------------------------


#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    bool validAnagram(string s1, string s2) {
        if(s1.size()!=s2.size()){return false;}
        unordered_map<char, int> mpp;
        for(char it: s1){
            mpp[it]++;
        }
        for(char it: s2){
            mpp[it]--;
        }
        for(char it:s1){
            if(mpp[it]!=0){return false;}
        }
        return true;
    }

};
