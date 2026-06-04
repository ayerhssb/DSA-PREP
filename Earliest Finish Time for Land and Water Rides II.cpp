class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int n=landStartTime.size(), m=waterStartTime.size(), minsum=INT_MAX, minWaterEndTime=INT_MAX,minLandEndTime=INT_MAX;

        for(int i=0;i<n;i++){
            minLandEndTime = min(minLandEndTime, landStartTime[i]+landDuration[i]);
        }
        for(int i=0;i<m;i++){
            minWaterEndTime = min(minWaterEndTime, waterStartTime[i]+waterDuration[i]);
            minsum = min(minsum, max(minLandEndTime, waterStartTime[i])+waterDuration[i]);
        }
        for(int i=0;i<n;i++){
            minsum = min(minsum, max(minWaterEndTime, landStartTime[i])+landDuration[i]);
        }



        // // water-ride--> second:
        // for(int i=0;i<m;i++){
        //     int sum=max(minLandEndTime,waterStartTime[i]+waterDuration[i]);
        //     // if(waterStartTime[i]>minLandEndTime){
        //     //     sum += (waterStartTime[i]-minLandEndTime);
        //     // }
        //     minsum = min(minsum, sum);
        // }

        // // land-ride--> second:
        // for(int i=0;i<n;i++){
        //     int sum=max(minWaterEndTime,landStartTime[i]+landDuration[i]);
        //     // if(landStartTime[i]>minWaterEndTime){
        //     //     sum += (landStartTime[i]-minWaterEndTime);
        //     // }
        //     minsum = min(minsum, sum);
        // }
        

        // vector<vector<int>> land, water;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(landStartTime[i]<=waterStartTime[j]){
        //             int sum = landStartTime[i]+ landDuration[i]+waterDuration[j];
        //             if(waterStartTime[j]>landStartTime[i]+landDuration[i]){
        //                 sum+=waterStartTime[j]-(landStartTime[i]+landDuration[i]);
        //             }
        //             minsum=min(minsum,sum);
        //         }
        //         if(landStartTime[i]>=waterStartTime[j]){
        //             int sum = waterStartTime[j]+ landDuration[i]+waterDuration[j];
        //             if(landStartTime[i]>waterStartTime[j]+waterDuration[j]){
        //                 sum+=landStartTime[i]-(waterStartTime[j]+waterDuration[j]);
        //             }
        //             minsum=min(minsum,sum);
        //         }
        //     }
        // }
        return minsum;
    }
};
