typedef long long ll;
class Node{
    Node* link[2];
    ll count=0;
    public:
        bool isContain(int num){
            return (link[num]!=nullptr);
        }
        void put(int num, Node* node){
            link[num] = node;
        }
        Node* get(int num){
            return link[num];
        }
        ll getCount(){
            return count;
        }
        void addCount(){
            count++;
        }
};

class Trie{
    private:
        Node* root;
        
    public:
        Trie(){
            root = new Node();
        }
        
        void insertNum(int num){
            Node* node =root;
            for(int i=31;i>=0;i--){
                int bit = ((num>>i)&1);
                if(!node->isContain(bit)){
                    node->put(bit, new Node());
                }
                node=node->get(bit);
                node->addCount();
            }
            
        }
        
        int getPair(int num, int k){
            Node* node =root;
            int add=0;
            for(int i=31;i>=0;i--){
                int bit = ((num>>i)&1);
                if(((k>>i)&1)){
                    if(node->isContain(bit)){
                        add+= node->get(bit)->getCount();
                    }
                    if(node->isContain(1-bit)){
                        node=node->get(1-bit);
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(node->isContain(bit)){
                        node=node->get(bit);
                    }
                    else{
                        break;
                    }
                }
            }
            return add;
        }
};


class Solution {
  public:
    int cntPairs(vector<int>& arr, int k) {
        Trie trie;
        int cnt=0;
        for(auto it:arr){
            cnt+=trie.getPair(it,k);
            trie.insertNum(it);
        }
        return cnt;
        
        //O(N^2)
        //  int cnt=0;
        //  for(int i=0;i<arr.size()-1;i++){
        //      for(int j=i+1;j<arr.size();j++){
        //         if((arr[i]^arr[j])<k){cnt++;}
        //      }
        //  }
        // return cnt;
    }
};
