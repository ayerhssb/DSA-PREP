//revision::

#include <bits/stdc++.h> 

struct Node{
    Node* links[26]={nullptr};
    bool flag;
    int cnt=0, prefixcnt=0;
    bool iscontain(char ch){
        return links[ch-'a']!=nullptr;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    void setend(){
        flag=true;
    }
    bool isend(){
        return flag;
    }
    void incend(){
        cnt++;
    }
    void decend(){
        cnt--;
    }
    void incprefixend(){
        prefixcnt++;
    }
    void decprefix(){
        prefixcnt--;
    }
    int getendcnt(){
        return cnt;
    }
    int getprefixcnt(){
        return prefixcnt;
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
        root = new Node();
    }
    ~Trie(){
        delete root;
    }
    void insert(string &word){
        Node* node=root;
        for(auto it:word){
            if(!node->iscontain(it)){
                node->put(it, new Node());
            }
            node=node->get(it);
            node->incprefixend();
        }
        node->incend();
    }

    int countWordsEqualTo(string &word){
        Node* node=root;
        for(auto it: word){
            if(!node->iscontain(it)){
                return 0;
            }
            node=node->get(it);
        }
        return node->getendcnt();
    }

    int countWordsStartingWith(string &word){
        Node* node=root;
        for(auto it:word){
            if(!node->iscontain(it)){
                return 0;
            }
            node=node->get(it);
        }
        return node->getprefixcnt();
    }

    void erase(string &word){
        Node* node=root;
        for(auto it: word){
            if(node->iscontain(it)){
                node=node->get(it);
                node->decprefix();
            }
            
            node->decend();
        }
    }
};




#include <bits/stdc++.h> 

struct Node{
    Node* links[26] = {nullptr};
    int cntEnd=0;
    int cntStart=0;
    bool isContainsKey(char ch){
        return (links[ch-'a']!=nullptr);
    }
    void put(char ch, Node* node){
        links[ch- 'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void addPrefix(){
        cntStart++;
    }
    void addEndCnt(){
        cntEnd++;
    }
    void delCntEnd(){
        cntEnd--;
    }
    void delCntPrefix(){
        cntStart--;
    }
};

class Trie{
    private:
        Node* root;
    public:

    Trie(){
        root= new Node();
    }
    // ~Trie(){
    //     delete root;
    // }

    void insert(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->isContainsKey(word[i])){
                node->put(word[i], new Node());
            }
            
            node=node->get(word[i]);
            node->addPrefix();
        }
        node->addEndCnt();
    }

    int countWordsEqualTo(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->isContainsKey(word[i])){
                return 0;
            }
            node=node->get(word[i]);
        }
        return node->cntEnd;
    }

    int countWordsStartingWith(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->isContainsKey(word[i])){
                return 0;
            }
            node=node->get(word[i]);
        }
        
        return node->cntStart;
    }

    void erase(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->isContainsKey(word[i])){
                return;
            }
            node=node->get(word[i]);
            node->delCntPrefix();
        }
        node->delCntEnd();
    }
};
