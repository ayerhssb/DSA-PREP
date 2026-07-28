#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    vector<int> getSortedSquares(vector<int>& arr) {
        //brute: 
        
        // vector<int> temp;
        // for(int i=0;i<arr.size();i++){
        //     temp.push_back(pow(arr[i],2));
        // }
        // sort(temp.begin(),temp.end());
        // return temp;
        
        //optimal : O(n)
        int n=arr.size();
        vector<int> temp(n);
        int left=0, right=n-1;
        for(int i=n-1;i>=0;i--){
            if(abs(arr[left])> abs(arr[right])){
                temp[i] = arr[left] *arr[left];
                left++;
            }
            else{
                temp[i] = arr[right] *arr[right];
                right--;
            }
        }
        return temp;
    }
};
