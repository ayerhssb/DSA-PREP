class Solution {
public:

    void helper(string s, string digits, vector<string>& ans, vector<string> phone_map){
        if(digits.empty()){
            ans.push_back(s);
            return;
        }
        else{
            string letters = phone_map[digits[0]- '2'];
            for(char it: letters){
                helper(s+it, digits.substr(1), ans,phone_map);
            }
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty())return ans;
        string s = "";
        vector<string> phone_map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        helper(s, digits, ans, phone_map);
        return ans;
    }
};
