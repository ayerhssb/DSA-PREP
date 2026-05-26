struct Node{
    Node* links[26]={nullptr};
    bool flag;
    bool iscontain(char ch){
        return links[ch-'a']!=nullptr;
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    bool isend(){
        return flag;
    }
    void setend(){
        flag=true;
    }
};

class Solution {
    private: 
    Node* root;
    public:
    
    Solution(){
        root = new Node();
    }
    
    void insertword(string& word){
        Node* node=root;
        for(auto it: word){
            if(!node->iscontain(it)){
                node->put(it,new Node());
            }
            node=node->get(it);
        }
        node->setend();
    }
    
    bool findword(string& word){
        Node* node=root;
        for(auto it: word){
            if(!node->iscontain(it)){
                return false;
            }
            node=node->get(it);
            if(!node->isend()){return false;}
        }
        return true;
    }
    
    string longestValidWord(vector<string>& words) {
        string ans="";
        for(int i=0;i<words.size();i++){
            insertword(words[i]);
        }
        for(auto it: words){
            if(findword(it)){
                if(ans.size()==it.size()){
                    if(it<ans){ans=it;}
                }else{
                    if(it.size()>ans.size()){
                        ans=it;
                    }
                }
            }
        }
        return ans;
    }
};
