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
