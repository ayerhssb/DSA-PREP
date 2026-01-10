class Solution {
  public:
    int atmost(string& s, int k){
        if(k<=0){
            return 0;
        }
        int arr[26] = {0};
        int l=0,n=s.size(),distinct=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            int ind = s[i]-'a';
            if(arr[ind]==0){
                distinct++;
            }
            arr[ind]++;
            
            while(distinct>k){
                arr[s[l]-'a']--;
                if(arr[s[l]-'a']==0){distinct--;}
                l++;
            }
            ans += (i-l+1);
        }
        return ans;
    }
    int countSubstr(string& s, int k) {
        return atmost(s,k)-atmost(s,k-1);
        // return exact(s,k);
    }
};
