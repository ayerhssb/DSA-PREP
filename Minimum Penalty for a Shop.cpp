class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size(),ans=0,mini=INT_MAX,addn=INT_MAX,ind;
        vector<int> close(n+1,0), open(n+1,0);
        for(int i=0;i<n;i++){
            if(customers[i]=='N'){
                open[i]=ans;
                ans+=1;
            }
            else{
                open[i]=ans;
            }
        }
        open[n]=ans;
        for(auto it:open){
            cout<<it<<" ";
        }
        cout<<endl;
        ans=0;
        for(int i=n-1;i>=0;i--){
            if(customers[i]=='Y'){
                ans+=1;
            }
            close[i]=ans;
        }
        for(auto it:close){
            cout<<it<<" ";
        }
        cout<<endl;
        for(int i=0;i<=n;i++){
            if(close[i]+open[i]<addn){addn=close[i]+open[i]; ind=i;}
            
        }
        return ind;
    }
    
};
