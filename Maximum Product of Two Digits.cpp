class Solution {
public:
    int maxProduct(int n) {
        int rem;
        vector<int> arr;
        while(n){
            rem = n%10;
            n=n/10;
            arr.push_back(rem);
        }
        sort(arr.begin(),arr.end());
        int prod = arr[arr.size()-1] * arr[arr.size()-2];
        return prod;
    }
};©leetcode
