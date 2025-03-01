class Solution {
  public:
    string decodedString(string &s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }
            else{
                string str="";
                string numstr="";
                while(!st.empty() && st.top()!='['){
                    str += st.top();
                    st.pop();
                }
                st.pop();
                reverse(str.begin(), str.end());
                while(!st.empty() && st.top()-'0'>=0 && st.top()-'0'<=9){
                    char chnum=st.top();
                    numstr+=chnum;
                    st.pop();
                }
                reverse(numstr.begin(), numstr.end());
                int num = stoi(numstr);
                string repeatedstr="";
                for(int i=0;i<num;i++){
                    repeatedstr += str;
                }
                for(char ch: repeatedstr){
                    st.push(ch);
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
