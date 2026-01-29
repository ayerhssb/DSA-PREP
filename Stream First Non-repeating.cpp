class Solution {
  public:
    string firstNonRepeating(string &s) {
        string ans=""; char ch='#';
        // unordered_map<char,int> mpp;
        vector<int> freq(26,0);
        queue<char> q;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']+=1;
            int flag=0;
            q.push(s[i]);
            while(!flag && !q.empty()){
                char top = q.front();
                if(freq[top-'a']>1){q.pop();}
                else{
                    ans+=top;
                    flag=1;
                }
            }
            if(!flag){ans+='#';}
            // if(mpp.find(s[i])!=mpp.end()){
            //     ans+=ch;
            // }
            // else{
            //     ans+=s[i];
            // }
            // mpp[s[i]]++;
            // if(mpp[s[i]]==1){ch=s[i];}
            // else{ch='#';}
        }
        return ans;
    }
};
