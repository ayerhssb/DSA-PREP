class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int> ans;
        if(n==0){return ans;}
        int all_nine=1, last_nine=0;
        for(int i=0;i<n;i++){
            if(digits[i]!=9){all_nine=0;break;}
        }
        if(digits[n-1]==9){last_nine=1;}
        if(all_nine){
            ans.push_back(1);
            int k=n;
            while(k--){
                ans.push_back(0);
            }
        }
        else if(last_nine){
            vector<int> arr(n);
            int carry=1,flag=1;
            for(int i=n-1;i>=0;i--){
                if(digits[i]==9&&flag){carry=1;arr[i]=0;}
                else{
                    arr[i]= digits[i]+carry;
                    carry=0;
                    flag=0;
                }
            }
            ans=arr;
        }
        else{
            ans=digits;
            ans[n-1]=digits[n-1]+1;
        }
        return ans;
        // string str="";
        
        // for(int it:digits){
        //     str += ('0'+it);
        // }
        // long long int num=stoi(str);
        // num++;
        // string str1 = to_string(num);
        // vector<int> ans(str1.size());
        // for(int i=str1.size()-1,j=0;i>=0,j<str1.size();i--,j++){
        //     ans[j]= (str1[j]-'0');
        // }
        // return ans;

    }
};
