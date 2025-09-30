class Solution {
  public:
    string Reduced_String(int k, string s) {
        string ans="";
        if(k==1){return ans;}
        stack<pair<char,int>> st;
        for(int i=0;i<s.size();i++){
            if(st.empty() || st.top().first != s[i]){
                st.push({s[i],1});
            }else{
                st.top().second++;
            }
            
            if(st.top().second==k){
                st.pop();
            }
        }
        while(!st.empty()){
            int cnt=st.top().second;
            while(cnt--){
                ans+= st.top().first;
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
