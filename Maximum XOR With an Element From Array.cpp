struct Node{
    Node* links[2] = {nullptr};
    bool iscontain(int num){
        return links[num]!=nullptr;
    }
    void put(int num , Node* node){
        links[num] = node;
    }
    Node* get(int num){
        return links[num];
    }

};
class Solution {
private:
Node* root;

public:
    Solution(){
        root=new Node();
    }

    void insert(int num){
        Node* node=root;
        
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(!node->iscontain(bit)){
                node->put(bit, new Node());
            }
            node=node->get(bit);
        }
    }
    int maxXor(int num){
        Node* node=root;
        int maxxor=0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(node->iscontain(1-bit)){
                maxxor|=(1<<i);
                node=node->get(1-bit);
            }else{
                node=node->get(bit);
            }
        }
        return maxxor;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size(), m=nums.size();
        vector<int> ans(n);
        sort(nums.begin(), nums.end());
        vector<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            q.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(q.begin(), q.end());
        int i=0;
        for(auto it:q){
            int maxi=-1;
            while(i<m && nums[i]<=it.first){
                insert(nums[i]);i++;
            }
            if(i!=0){
                ans[it.second.second] = maxXor(it.second.first);
            }else{
                ans[it.second.second] = -1;
            }
        }
        return ans;
    }
};
