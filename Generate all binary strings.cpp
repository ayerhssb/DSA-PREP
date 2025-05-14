class Solution {
  public:
    void helper(int num, string list, vector<string> &ans, int ind, int prev_num){
        if(ind==num){
            ans.push_back(list);
            return;
        }
        
        
            helper(num, list+'0', ans,ind+1,0);
            if(prev_num!=1){helper(num, list+'1', ans,ind+1,1);}
            if(!list.empty()){list.pop_back();}
        
    }
    vector<string> generateBinaryStrings(int num) {
        vector<string> ans;
        string list;
        helper(num,list,ans,0,0);
        
        return ans;
    }
};
