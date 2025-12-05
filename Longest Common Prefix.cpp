struct Node{
    Node* links[26]={nullptr};
    int countPrefix=0;
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

    int countChildern(Node* node){
        int count=0;
        for(int i=0;i<26;i++){
            if(links[i]!=nullptr){
                count++;
            }
        }
        return count;
    }
    void increasePrefix(){
        countPrefix++;
    }
    void setEnd(){
        flag=true;
    }
    bool getEnd(){
        return flag;
    }
    int getPrefixCount(){
        return countPrefix;
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
                node->increasePrefix();
            }
            node->setEnd();
        }

        

        string findPrefix(){
            Node* node=root;
            string prefix="";
            while(!node->getEnd() && node->countChildern(node)==1){
                for(int i=0;i<26;i++){
                    char ch = 'a'+i;
                    if(node->containsKey(ch)){
                        prefix+=ch;
                        node=node->get(ch);
                        break;
                    }
                }
            }

            return prefix;
        }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        for(auto it: strs){
            if(it==""){return "";}
            trie.insert(it);
        }
        string ans = trie.findPrefix();
        return ans;
    }
};
