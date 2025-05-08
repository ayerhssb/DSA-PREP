class Solution {
public:
    void helper(int n, int op, int cl, string s, vector<string>& ans){
        if(op==0 &&cl==0){
            ans.push_back(s);
            return;
        }
        if(op==cl){
            string s1=s;
            helper(n,op-1,cl,s1+'(',ans);
        }
        else if(op==0){
            string s1=s;
            helper(n,op,cl-1,s1+')',ans);
            
        }
        else if(cl==0){
            string s1=s;
            helper(n,op-1,cl,s1+'(',ans);
            
        }
        else{
            string s1=s;
            string s2=s;
            helper(n,op-1,cl,s1+'(',ans);
            helper(n,op,cl-1,s2+')',ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        int op = n, cl = n;
        vector<string> ans;
        string s ="";
        helper(n,op,cl,s,ans);
        return ans;
    }
};
