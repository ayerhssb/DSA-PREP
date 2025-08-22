class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans(2);
        int maxi=-1,row=-1;
        for(int i=0;i<mat.size();i++){
            int ones=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){ones++;}
            }
            int temp=maxi;
            maxi=max(maxi,ones);
            if(temp!=maxi){row=i;}
            else{row=min(row,i);}
        }
        ans[0]=row;
        ans[1]=maxi;
        return ans;
    }
};
