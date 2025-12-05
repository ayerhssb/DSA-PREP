struct Node{
    Node* links[26]={nullptr};
    
    bool flag=false;
    bool containsKey(char ch){
        return (links[ch-'a']!=nullptr);
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag=true;
    }
    bool getEnd(){
        return flag;
    }
    
    ~Node(){
        for(int i=0;i<26;i++){
            if(links[i]!=nullptr){
                delete links[i];
                links[i]=nullptr;
            }
        }
    }

};

class Trie{
    private:
    Node* root;

    public:
        Trie(){
            root = new Node;
        }
        ~Trie(){
            delete root;
        }

        void insert(string &word){
            Node* node = root;

            for(auto it:word){
                if(!node->containsKey(it)){
                    node->put(it, new Node());
                }
                node=node->get(it);
                
            }
            node->setEnd();
        }
};


class Solution {
  public:
    int countSubs(string& s) {
        Node* root= new Node();
        int count=0;
        
        for(int i=0;i<s.size();i++){
            Node* node = root;
            for(int j=i;j<s.size();j++){
                if(!node->containsKey(s[j])){
                    node->put(s[j],new Node());
                    count++;
                }
                node=node->get(s[j]);
            }
        }
        return count;
        // int count=0;
        // unordered_map<string,int> mpp;
        // for(int i=0;i<s.size();i++){
        //     string ans="";
        //     for(int j=i;j<s.size();j++){
        //         ans+=s[j];
        //         if(mpp.find(ans)==mpp.end()){count++;mpp[ans]++;}
        //     }
        // }
        // return count;
    }
};
