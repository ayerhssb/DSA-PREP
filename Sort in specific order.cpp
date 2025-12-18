//Constant space solution:
class Solution {
  public:
    void sortIt(vector<int>& arr) {
        //O(1) Space:
        int n=arr.size();
        int l=0,r=n-1;
        while(l<=r){
            if(arr[l]%2==0 && arr[r]%2){
                swap(arr[l],arr[r]);
                l++;r--;
            }
            else if(arr[l]%2==0){
                r--;
            }
            else if(arr[r]%2){
                l++;
            }
            else{
                l++;r--;
            }
        }
        int ind=-1;
        for(int i=0;i<n;i++){
            if(arr[i]%2==0){
                ind=i;
                break;
            }
            // cout<<arr[i]<< " ";
        }
        if( ind==0){
            sort(arr.begin(),arr.end());
            return;
        }
        if(ind==-1 ){
            sort(arr.begin(),arr.end(), [&](const int a, const int b){return a>b;});
            return;
        }
        
        sort(arr.begin(),arr.begin()+ind, [&](const int a, const int b){return a>b;});
        sort(arr.begin()+ind,arr.end());
        
        // vector<int> even, odd;
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i]%2){odd.push_back(arr[i]);}
        //     else{even.push_back(arr[i]);}
        // }
        // sort(odd.begin(),odd.end(),[&](const int a, const int b){
        //     return a>b;
        // });
        // sort(even.begin(),even.end());
        // for(int i=0;i<odd.size();i++){
        //     arr[i]=odd[i];
        // }
        // for(int i=0;i<even.size();i++){
        //     arr[i+odd.size()]=even[i];
        // }
        
    }
};

class Solution {
  public:
    void sortIt(vector<int>& arr) {
        vector<int> even, odd;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2){odd.push_back(arr[i]);}
            else{even.push_back(arr[i]);}
        }
        sort(odd.begin(),odd.end(),[&](const int a, const int b){
            return a>b;
        });
        sort(even.begin(),even.end());
        for(int i=0;i<odd.size();i++){
            arr[i]=odd[i];
        }
        for(int i=0;i<even.size();i++){
            arr[i+odd.size()]=even[i];
        }
        
    }
};
