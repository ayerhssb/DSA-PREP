class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0, start=-1,end;
        for(int i=1;i<prices.size();i++){

            if(prices[i-1]-prices[i]==1){
                if(start==-1){start=i-1;end=-1;}
                if(i==prices.size()-1){end=i;long long n=end-start+1;
                    ans+= (n*(n-1)/2);}
            }
            else{
                if(start>=0){
                    end=i-1;
                    long long n=end-start+1;
                    ans+= (n*(n-1)/2);
                }
                start=-1;
            }
            
        }
        ans+=prices.size();
        return ans;
    }
};
