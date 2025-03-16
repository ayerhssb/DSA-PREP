class Solution {
public:
long long maxEl(vector<int>& ranks, int cars){
    long long el=INT_MIN * 1ll;
    for(int i=0;i<ranks.size();i++){
        if(ranks[i]>el){
            el=ranks[i];
        }
    }

    return el*cars*cars;
}
    bool mintime(long long mid, vector<int>& ranks, int cars){
        long long no_cars=0;
        for(int i=0;i<ranks.size();i++){
                no_cars += floor(sqrt(mid/ranks[i]));
        }
        if(no_cars>=cars){
            return true;
        }

        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long start= 1* 1ll , end = maxEl(ranks,cars) ;
        while(start<=end){
            long long mid = (start+end)>>1 * 1ll;
            if(mintime(mid,ranks,cars)){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
};
