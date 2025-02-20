class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> str;
        queue<string> q;

        q.push("a");
        q.push("b");
        q.push("c");
        
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            if(curr.size()==n){
                str.push_back(curr);
                continue;
            }

            string first = curr;
            string second = curr;
            if(curr.back() =='a'){
                first.push_back('b');
                second.push_back('c');
            }
            else if(curr.back()=='b'){
                first.push_back('a');
                second.push_back('c');
            }
            else{
                first.push_back('a');
                second.push_back('b');
            }

            q.push(first);
            q.push(second);
        }
        if(k>str.size()){
            return "";
        }

        return str[k-1];
    }
};
