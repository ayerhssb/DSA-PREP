class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp=arr;
        sort(temp.begin(), temp.end());
        unordered_map<int,int> mpp;
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(mpp.find(temp[i])!=mpp.end()){continue;}
            mpp[temp[i]] = cnt+1;
            cnt++;
        }

        for(int i=0;i<arr.size();i++){
            arr[i] = mpp[arr[i]];
        }
        return arr;
    }
};
