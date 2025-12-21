//OPTIMISED(Currently using stl functions):

class Solution {
  public:
    // int upperbound(int l,int h, int num, vector<int> &arr){
    //     while(l<=h){
    //         int mid=(l+h)>>1;
    //         if(arr[mid]<=num){
    //             l=mid+1;
    //         }
    //         else{
    //             h=mid-1;
    //         }
    //     }
    //     return l;
    // }
    // int lowerbound(int l,int h, int num, vector<int> &arr){
        
    //     while(l<=h){
    //         int mid=(l+h)>>1;
    //         if(arr[mid]<num){
    //             l=mid+1;
    //         }
    //         else{
    //             h=mid-1;
    //         }
    //     }
    //     return l;
    // }
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int cnt=0;
            int up=upper_bound(arr.begin()+queries[i][0],arr.begin()+queries[i][1]+1,queries[i][2])-arr.begin();
            int lb=lower_bound(arr.begin()+queries[i][0],arr.begin()+queries[i][1]+1,queries[i][2])-arr.begin();
            if(arr[lb]!=queries[i][2] || lb>queries[i][1]){cnt=0;}
            else{cnt=up-lb;}
            ans.push_back(cnt);
        }
        return ans;
    }
};

//TLE
class Solution {
  public:
    int Search(int left, int right, int num,vector<int>& arr){
        int cnt=0;
        while(left<=right){
            int mid=(left+right)>>1;
            if(arr[mid]==num){
                cnt++;
                // cout<<"first time cnt: "<<cnt<<endl;
                int i=mid+1, j=mid-1;
                
                    while(arr[mid]==arr[i]&&i<=right){
                        cnt++;i++;
                    }
                    while(arr[mid]==arr[j] && j>=left){
                        cnt++;j--;
                    }
                
                return cnt;
            }
            if(arr[mid]<num){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return cnt;
    }
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int cnt= Search(queries[i][0],queries[i][1],queries[i][2],arr);
            ans.push_back(cnt);
        }
        return ans;
    }
};
