class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xor_all=0;
        for(int it:derived){
            xor_all = xor_all^it;
        }
        if(xor_all==0){
            return true;
        }
        return false;
    }
};
