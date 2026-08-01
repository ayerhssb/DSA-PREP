//descending order using selection sort --> O(n^2) TC

#include <bits/stdc++.h>
using namespace std;

class solution {
    public:
    void selectionSort(int arr[], int n){
        for(int i=0;i<n;i++){
            int maxi=i;
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[maxi]){
                    maxi=j;
                }
            }
            swap(arr[i], arr[maxi]);
        }
    }
};

// --------------------------------------------------------------------------------



#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    void selectionSort(int arr[], int n){
        for(int i=0;i<n-1;i++){
            int mini=arr[i], idx=i;
            for(int j=i+1;j<n;j++){
                if(arr[j]<mini){
                    mini=arr[j];
                    idx=j;
                }
            }
            swap(arr[i], arr[idx]);
            
        }
    }
};
