//good question --> Trie + DFS 
//similar to word break II

#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26] = {nullptr};
    bool flag=0;
    
    bool iscontainkey(char ch){
        return links[ch-'a']!=nullptr;
    }
    
    Node* getkey(char ch){
        return links[ch-'a'];
    }
    
    void putkey(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    void setend(){
        flag=1;
    }
    bool isend(){
        return flag;
    }
};

class solution{
    private: 
        Node* root;
    public:
    
    solution(){
        root= new Node();
    }
    ~solution(){
        delete root;
    }
    
    void insertword(string str){
        Node* node= root;
        for(int i=0;i<str.size();i++){
            if(!node->iscontainkey(str[i])){
                node->putkey(str[i], new Node());
            }
            node=node->getkey(str[i]);
        }
        node->setend();
    }
    
    vector<string> dfs(int n, string& text, int idx, vector<string>& path, vector<string>& ans){
        if(idx==n){
            string sentence="";
            for(int i=0;i<path.size();i++){
                if(i){sentence+=" ";}
                sentence+=path[i];
            }
            ans.push_back(sentence);
            return ans;
        }
        Node* node=root;
        string word="";
        for(int i=idx;i<n;i++){
            if(!node->iscontainkey(text[i])){
                break;
            }
            node=node->getkey(text[i]);
            word+=text[i];
            
            if(node->isend()){
                path.push_back(word);
                dfs(n,text,i+1, path, ans);
                path.pop_back();
            }
        }
        return ans;
        
    }
    
    // vector<string> find(string& text,int n, vector<string>& ans){
    //     Node* node= root;
    //     string str="";
    //     for(int i=0;i<n;i++){
    //         if(!node->iscontainkey(text[i])){
    //             return {};
    //         }
    //         node=node->getkey(text[i]);
    //         str+=text[i];
    //         if(node->isend()){
    //             ans.push_back(str);
    //             str="";
    //         }
    //     }
    //     return ans;
    // }
    vector<string> wordSegmentation(int n, int m, string text, vector<string>& dictionary) {
      vector<string> ans;
      for(int i=0;i<m;i++){
          insertword(dictionary[i]);
      }
      vector<string> path;
      return dfs(n,text,0,path,ans);
    }
};
