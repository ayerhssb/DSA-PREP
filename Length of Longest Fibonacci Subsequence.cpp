class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> values(arr.begin(),arr.end());

        int longest=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int a=arr[i];
                int b=arr[j];
                int count=2;
                while(values.count(a+b)>0){
                    int sum = a+b;
                    a=b;
                    b=sum;
                    count++;
                }
                if(count>2){
                    longest = max(longest, count);
                }
            }
        }
        return longest;
    }
};
