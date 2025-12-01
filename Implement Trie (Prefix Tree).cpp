struct Node{
    Node* links[26] = {nullptr};

    bool flag;
    bool isContainsKey(char ch){
        return links[ch-'a']!=nullptr;
    }
    void put(char ch, Node* node){
        links[ch- 'a'] = node;
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

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    ~Trie(){
        delete root;
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->isContainsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]); 
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->isContainsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->getEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node= root;
        for(int i=0;i<prefix.size();i++){
            if(!node->isContainsKey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
            // if(!node->getEnd()){return false;}
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
