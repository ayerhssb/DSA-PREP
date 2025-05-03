class Solution {
public:

    int getRotations(vector<int>& tops, vector<int>& bottoms, int target){
        int swap_b=0, swap_top=0;
        for(int i=0;i<tops.size();i++){
            if(tops[i]!=target && bottoms[i]!=target){
                return INT_MAX;
            }
            if(bottoms[i]!=target){
                swap_b++;
            }
            if(tops[i]!=target){
                swap_top++;
            }
        }

        return min(swap_b, swap_top);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res = getRotations(tops, bottoms, tops[0]);
        if(tops[0] != bottoms[0]){
            res = min(res, getRotations(tops, bottoms, bottoms[0]));
        }

        return res == INT_MAX ? -1 : res;
    }
};
