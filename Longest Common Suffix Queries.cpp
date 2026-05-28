struct Node {

    int links[26];
    int len, ind;

    Node() {
        memset(links, -1, sizeof(links));
        len = 1e9;
        ind = 0;
    }

    // bool iscontain(char ch) { return links[ch - 'a'] != -1; }

    // void put(char ch, int num) { links[ch - 'a'] = num; }

    // int get(char ch) { return links[ch - 'a']; }
    // int getlen() { return len; }
    // void setlen(int num) { len = num; }
    // void setind(int num) { ind = num; }
    // int getind() { return ind; }
};

class Solution {
private:
    vector<Node> trie;

public:
    // Solution() { root = new Node(); }
    // Node* root = new Node();
    Solution() {
        trie.reserve(500005);
        trie.push_back(Node());
    }

    void insert(string& word, int ind) {
        // Node* node = root;
        int node = 0;
        int length = (int)word.size();

        // update root
        if (trie[node].len > length) {
            trie[node].len = length;
            trie[node].ind = ind;
        } else if (trie[node].len == length && ind < trie[node].ind) {
            trie[node].ind = ind;
        }

        for (int i = (int)length - 1; i >= 0; --i) {
            int c = word[i] - 'a';
            if (trie[node].links[c] == -1) {

                int newNode = trie.size();

                trie.push_back(Node());

                trie[node].links[c] = newNode;
            }

            // node = node->get(word[i]);
            node = trie[node].links[c];

            // update every node
            if (trie[node].len > length) {
                trie[node].len = length;
                trie[node].ind = ind;
            } else if (trie[node].len == length && ind < trie[node].ind) {
                trie[node].ind = ind;
            }
        }

        // node->setend();
    }

    // void insert(string& word, int ind) {
    //     Node* node = root;
    //     int length = word.size();
    //     for (int i = length - 1; i >= 0; i--) {
    //         // cout<<word[i]<<"\n";
    //         if (root->getlen() > length) {
    //             root->setlen(length);
    //             root->setind(ind);
    //         } else if (root->getlen() == length && ind < root->getind()) {
    //             root->setind(ind);
    //         }
    //         if (!node->iscontain(word[i])) {
    //             node->put(word[i], new Node());
    //         }
    //         node = node->get(word[i]);
    //     }
    //     node->setend();
    // }
    int lcs(string& suff) {

        int node = 0;
        for (int i = (int)suff.size() - 1; i >= 0; i--) {
            int c = suff[i] - 'a';
            if (trie[node].links[c] != -1) {
                // node = node->get(suff[i]);
                node = trie[node].links[c];

            } else {
                break;
            }
        }
        return trie[node].ind;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        int n = wordsQuery.size(), m = wordsContainer.size();
        vector<int> ans(n);
        int smallestlen = INT_MAX, smallestidx = 0;
        for (int i = 0; i < m; i++) {
            insert(wordsContainer[i], i);
            if (smallestlen > wordsContainer[i].size()) {
                smallestlen = wordsContainer[i].size();
                smallestidx = i;
            }
        }

        for (int i = 0; i < n; i++) {
            int num = lcs(wordsQuery[i]);
            ans[i] = num;
        }

        return ans;
    }
};



//my implementation trie-- MLEEEEEEEEE



// struct Node{
//     Node* links[26];
//     bool flag;
//     int len, ind;

//     Node(){
//         for(int i=0;i<26;i++) links[i]=nullptr;
//         flag=false;
//         len=INT_MAX;
//         ind=0;
//     }
//     bool iscontain(char ch){
//         return links[ch-'a']!=nullptr;
//     }

//     void put(char ch, Node* node){
//         links[ch-'a']= node;
//     }

//     Node* get(char ch){
//         return links[ch-'a'];
//     }
//     bool isend(){
//         return flag;
//     }

//     void setend(){
//         flag=true;
//     }
//     int getlen(){
//         return len;
//     }
//     void setlen(int num){
//         len=num;
//     }
//     void setind(int num){
//         ind=num;
//     }
//     int getind(){
//         return ind;
//     }

    // ~Node(){
    //     for(int i=0;i<26;i++){
    //         if(links[i]!=nullptr){
    //             delete links[i];
    //             links[i]=nullptr;
    //         }
    //     }
    // }
// };


// class Solution {
// private:
// Node* root;
// public:
//     Solution(){
//         root=new Node();
//     }

//     void insert(string& word, int ind){
//         Node* node=root;
//         int length=word.size();
//         for(int i=length-1;i>=0;i--){
//             // cout<<word[i]<<"\n";
//             if(!node->iscontain(word[i])){
//                 node->put(word[i], new Node());
//             }
//             node=node->get(word[i]);
//             if(node->getlen()>length){
//                 node->setlen(length);
//                 node->setind(ind);
//             }
//             else if(node->getlen()==length){
//                 if(ind<node->getind()){
//                     node->setind(ind);
//                 }
//             }
//         }
//         node->setend();
//     }
//     int lcs(string& suff, int ind){
//         Node* node=root;
//         int ans=0,cnt=0;
//         for(int i=suff.size()-1;i>=0;i--){
//             if(node->iscontain(suff[i])){
//                 node=node->get(suff[i]);
//                 cnt++;
//             }
//             else{break;}
//         }
//         if(cnt){ans=node->getind();}else{
//             ans=ind;
//         }
//         return ans;
//     }

//     vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
//         int n = wordsQuery.size(), m=wordsContainer.size();
//         vector<int> ans(n);
//         int smallestlen=INT_MAX, smallestidx=0;
//         for(int i=0;i<m;i++){
//             insert(wordsContainer[i],i);
//             if(smallestlen>wordsContainer[i].size()){smallestlen= wordsContainer[i].size();smallestidx=i;}
//         }

//         for(int i=0;i<n;i++){
//             int num = lcs(wordsQuery[i], smallestidx);
//             ans[i]=num;
//         }

//         return ans;
//     }
// };

