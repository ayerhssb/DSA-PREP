class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt=0;
        unordered_set<char> st;
        for(auto it:word){
            st.insert(it);
        }
        for(auto it: st){
            if(islower(it)&& st.find(it-32)!=st.end()){
                cnt++;
            }
            else if(isupper(it)&& st.find(it+32)!=st.end()){
                cnt++;
            }
            // st.insert(word[i]);
        }
        return cnt/2;
    }
};
