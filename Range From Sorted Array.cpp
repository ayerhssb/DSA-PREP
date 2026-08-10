#include <bits/stdc++.h>
using namespace std;

class solution {
   public:
    vector<string> getRanges(vector<int>& numbers) {
        int left=0, right=0, n=numbers.size();
        vector<string> ans;
        while(right<n-1 && left<=right){
            if((numbers[right+1] - numbers[right])!=1){
                if(left==right){ans.push_back(to_string(numbers[right]));}
                else{string str = to_string(numbers[left])+"->"+to_string(numbers[right]);
                ans.push_back(str);}
                left=right+1;
            }
            right++;
        }
        if((numbers[right]-numbers[right-1])!=1){
            string str = to_string(numbers[right]);
            ans.push_back(str);
        }
        else{
            string str = to_string(numbers[left])+"->"+to_string(numbers[right]);
            ans.push_back(str);
        }
        return ans;
    }
};
