class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int init=0;
        for(int i=0;i<s2.size();i++){
            if(s1[i]!=s2[i]){
                init = i+1;
                break;
            }
        }
        for(int j= init;j<s2.size();j++){
            if(s2[j]!=s1[j]){
                swap(s2[j],s2[init-1]);
                break;
            }
        }
        cout<< s2;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){return false;}
        }

        return true;
    }
};
