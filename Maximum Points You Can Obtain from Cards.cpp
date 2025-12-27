class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int goal=n-k;
        int l=0,r=goal-1,sum=0,mini=INT_MAX,totalSum=0;
        for(auto it:cardPoints){totalSum+=it;}
        for(int i=0;i<=r;i++){sum+=cardPoints[i];}
        r++;mini=min(mini,sum);
        while(r<n){
            sum+=cardPoints[r]; sum-=cardPoints[l];l++;
            mini=min(mini,sum);
            r++;
        }
        cout<<totalSum<<" :total "<<mini<<" :min ";
        return totalSum-mini;
    }
};
