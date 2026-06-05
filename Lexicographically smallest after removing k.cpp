class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) {
        
        int n=s.size(); string ans="";
        if(n > 0 && (n & (n - 1)) == 0){
            k=k/2;
        }else{
            k=k*2;
        }
        if(k>=n){
            return "-1";
        }
        stack<char> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&s[i]<st.top()&&k>0){st.pop();k--;}
            st.push(s[i]);
        }
        if(k>0){while(k--){st.pop();}}
        while(!st.empty()){
            ans+=st.top();st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
