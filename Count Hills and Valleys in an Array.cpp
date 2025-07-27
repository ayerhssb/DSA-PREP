class Solution {
public:
    int countHillValley(vector<int>& arr) {
        vector<int> temp;
        int cnt=0;
        temp.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            if(arr[i]!=arr[i-1]){
                temp.push_back(arr[i]);
            }
        }
        for(int i=0;i<temp.size();i++){
            cout<< temp[i]<< " ";
        }
        for(int i=1;i<temp.size()-1;i++){
            if((temp[i]<temp[i-1] && temp[i]<temp[i+1]) || (temp[i]>temp[i-1] && temp[i]>temp[i+1])){
                cnt++;
            }
        }
        return cnt;
    }
};
