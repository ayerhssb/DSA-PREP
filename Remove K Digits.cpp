class Solution {
  public:
    string removeKdig(string &s, int k) {
        int n=s.size(), len=n-k;
        string ans;
        stack<char> st;
        for(auto it:s){
            while(!st.empty()&& (st.top()>it) &&k>0){
                st.pop();k--;
            }
            if(!st.empty()||it!='0')st.push(it);
        }
        while(!st.empty() && k--){
            st.pop();
        }
        if(st.empty()){return "0";}
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        // string ans= s.substr(n-k, n-k);
        // for(int i=0;i<=n-k;i++){
        //     int dig=i,j=n-k-1;
        //     while(j>=0){
        //         if(s[j]-'0'<ans[i]-'0' && s[j]-'0'<s[dig]-'0'){
        //             dig = j;
        //         }
        //         j--;
        //     }
        //     swap(ans[i],s[dig]);
        // }
        // cout<<ans<<endl;
        return ans;
    }
};
