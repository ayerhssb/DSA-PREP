class Solution {
public:
    bool isTrionic(vector<int>& arr) {
        int cnt=0,n=arr.size();
        int p=0;
        if(n<=3){return false;}
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){return false;}
            if(arr[i]<arr[i-1]){cnt++;p=i-1;break;}
            if(cnt>2){return false;}
        }
        if(p==0){return false;}
        for(int i=p+1;i<n;i++){
            if(arr[i]==arr[i-1]){return false;}
            if(arr[i]>arr[i-1]){cnt++;p=i-1;break;}
            if(cnt>2){return false;}
        }
        for(int i=p+1;i<n;i++){
            if(arr[i]==arr[i-1]){return false;}
            if(arr[i]<arr[i-1]){return false;}
        }
        if(cnt==2){return true;}
        return false;
    }
};
