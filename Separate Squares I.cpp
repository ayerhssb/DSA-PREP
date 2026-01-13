class Solution {
public:
    pair<int,int> El(vector<vector<int>>& squares){
        int low=INT_MAX,high=INT_MIN;
        for(int i=0;i<squares.size();i++){
            low=min(low,squares[i][1]);
            high=max(high,squares[i][1]+squares[i][2]);
        }
        return {low,high};
    }

    double totalArea(vector<vector<int>>& squares){
        double tArea=0;
        for(int i=0;i<squares.size();i++){
            tArea+= (pow(squares[i][2],2));
        }
        return tArea;
    }


    double LowerArea(vector<vector<int>>& squares, double y){
        double lowerArea=0,upperArea=0;
        for(int i=0;i<squares.size();i++){
            double ymax=squares[i][1]+squares[i][2], ymin=squares[i][1];
            double len=squares[i][2];
            if(ymin>=y){continue;}
            else if(ymin<y && ymax>=y){
                lowerArea+= (len*(y-ymin));
            }
            else{
                lowerArea+= (len*len);
            }
        }
        return lowerArea;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double l=El(squares).first, h= El(squares).second;
        double totalarea = totalArea(squares);
        double half = totalarea/2.0;
        const double epsilon = 1e-5;
        while(h-l> epsilon){
            double mid = (l+h)/2;
            if(LowerArea(squares, mid)>=half){
                h=mid;
            }
            else{
                l=mid;
            }
        }
        return l;
    }
};
