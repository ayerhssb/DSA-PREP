class Solution {
public:
    void addtoset(string& s, unordered_set<string>& st){
        for(int i=1;i<=s.size();i++){
            st.insert(s.substr(0,i));
        }
    }
    int checklcp(string& s, unordered_set<string>& st){
        int ans=0;
        for(int i=s.size();i>=1;i--){
            string s1 = s.substr(0,i);
            cout<<s1<<"\n";
            if(st.find(s1)!=st.end()){
                // ans = max(ans, s1.size());
                cout<<"size: "<<s1.size()<<"\n";
                ans=s1.size();
                break;
            }
        }
        return ans;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // unordered_set<string> st; int ans, maxi=0;
        // for(int i=0;i<arr1.size();i++){
        //     string s = to_string(arr1[i]);
        //     addtoset(s,st);
        // }

        // for(int i=0;i<arr2.size();i++){
        //     string s = to_string(arr2[i]);
        //     ans = checklcp(s,st);
        //     maxi=max(maxi,ans);
        // }

        // for(auto it:st){
        //     cout<<it<<"\n";
        // }
        // return maxi;

        //better:

        unordered_set<int> st;
        int ans=0;
        for(auto it: arr1){
            int x=it;
            while(x>0){
                st.insert(x);
                x=x/10;
            }
        }
        for(auto it:arr2){
            int x=it;
            string s= to_string(x);
            int len =s.size();

            while(x>0){
                if(st.find(x)!=st.end()){
                    ans=max(ans,len);
                    break;
                }
                len--;
                x=x/10;
            }
        }

        return ans;
    }
};
