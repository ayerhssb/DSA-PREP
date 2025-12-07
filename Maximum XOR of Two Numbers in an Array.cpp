struct Node{
public:
    Node* links[2];
    bool containsKey(int bit){
        return (links[bit]!=nullptr);
    }
    void put(int bit, Node* node){
        links[bit]=node;
    }
    Node* get(int bit){
        return links[bit];
    }
    // ~Node(){

    // }

};

class Solution {
Node* root;
public:
    Solution(){
        root = new Node();
    }
    // ~Solution(){
    //     delete root;
    // }
    void insert(int num){
        Node* node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node=node->get(bit);
        }
    }
    int maxXor(int num){
        Node* node = root;
        int maxxor=0;
        for(int i=31;i>=0;i--){
            int bit= (num>>i)&1;
            if(node->containsKey(1-bit)){
                maxxor = maxxor| (1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxxor;
    }
    int findMaximumXOR(vector<int>& nums) {
        int ans=0;
        for(auto it:nums){
            insert(it);
        }
        for(auto it:nums){
            ans = max(ans, maxXor(it));
        }
        return ans;
    }
};
