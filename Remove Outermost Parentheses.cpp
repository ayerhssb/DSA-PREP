class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=1;
        string ans;
        for(int i=1;i<s.size();i++){
            if(s[i]=='('){cnt++;}
            else{cnt--;}
            if(cnt>0){
                ans.push_back(s[i]);
            }
            if(cnt==0){cnt=1;i++;}
        }
        return ans;
    }
};
