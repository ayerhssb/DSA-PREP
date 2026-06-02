//check constraints for brute force

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<vector<int>> land, water;
        // for(int i=0;i<landStartTime.size();i++){
        //     land.push_back({landDuration[i],landStartTime[i]});
        // }
        // for(int i=0;i<landStartTime.size();i++){
        //     water.push_back({waterDuration[i],waterStartTime[i]});
        // }
        // sort(land.begin(), land.end(),[&](const a, const b){
        //     return a[0]+a[1]<b[0]+b[1];
        // })

        // sort(water.begin(), water.end(),[&](const a, const b){
        //     return a[0]+a[1]<b[0]+b[1];
        // })
        // int l=land.size(),w=water.size();
        // int i=0,j=0;
        // while(i<l &&j<w){
            
        // }
        int n=landStartTime.size(), m=waterStartTime.size(), minsum=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(landStartTime[i]<=waterStartTime[j]){
                    int sum = landStartTime[i]+ landDuration[i]+waterDuration[j];
                    if(waterStartTime[j]>landStartTime[i]+landDuration[i]){
                        sum+=waterStartTime[j]-(landStartTime[i]+landDuration[i]);
                    }
                    minsum=min(minsum,sum);
                }
                if(landStartTime[i]>=waterStartTime[j]){
                    int sum = waterStartTime[j]+ landDuration[i]+waterDuration[j];
                    if(landStartTime[i]>waterStartTime[j]+waterDuration[j]){
                        sum+=landStartTime[i]-(waterStartTime[j]+waterDuration[j]);
                    }
                    minsum=min(minsum,sum);
                }
            }
        }
        return minsum;
    }
};
