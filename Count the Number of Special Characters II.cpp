class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> low(26,INT_MAX), cap(26,0);
        int cnt=0;
        for(int i=0;i<word.size();i++){
            if(islower(word[i])){
                low[word[i]-'a']=i;
            }
        }

        for(int i=0;i<word.size();i++){
            
            if(isupper(word[i]) && low[(word[i]+32) - 'a']<i && (!cap[word[i]-'A'])){
                cout<< "letter: "<< word[i]+32-'a';
                cnt++;
                cap[word[i]-'A']=1;
            }
            else if(isupper(word[i])){
                cap[word[i]-'A']=1;
            }
        }
        return cnt;
    }
};
