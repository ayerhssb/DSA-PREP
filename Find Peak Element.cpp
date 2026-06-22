// rev::

#include <bits/stdc++.h>
using namespace std;

class solution{
public:
    int findPeakElement(int arr[], int n) {
        if(n==1){return arr[0];}
        int ans;
        if(arr[0]>arr[1]){ans=0;}
        if(arr[n-1]>arr[n-2]){ans=n-1;}
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                ans=i;break;
            }
        }
        return ans;
    }
};

// ---------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class solution{
public:
    int findPeakElement(int arr[], int n) {
        if(arr[0]>arr[1]){
            return 0;
        }
        if(arr[n-1]>arr[n-2]){
            return n-1;
        }
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i+1] && (arr[i]>arr[i-1])){
                return i;
            }
        }
       return -1; 
    }
};
