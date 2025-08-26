class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        float longestdia=0.0;
        int maxArea=0;
        // int temp=longestdia;
        for(int i=0;i<dimensions.size();i++){
            float diagonal = sqrt(pow(dimensions[i][0], 2)+pow(dimensions[i][1], 2));
            int area=dimensions[i][0]*dimensions[i][1];
            
            cout <<"longest dia: " <<longestdia;
            cout <<" dia: " <<diagonal;
            // if(temp==diagonal){maxArea = max(area,maxArea);}
            // else{
                if(longestdia==diagonal){maxArea = max(maxArea,area);}
                else if(longestdia<diagonal){maxArea = area;}
                else{continue;}
                cout<<" area: "<<maxArea<<endl;
                longestdia = max(longestdia,diagonal);
            // }
            // temp=longestdia;
        }
        return maxArea;
    }
};
