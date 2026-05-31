//revision::


class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size(); vector<pair<double,int>> ratio(n); 
        for(int i=0;i<n;i++){
            ratio[i].first=double(val[i])/wt[i];
            ratio[i].second=i;
        }
        
        
        
        sort(ratio.begin(),ratio.end(),[](const auto& a, const auto& b){
            return a.first>b.first;
        });
        double sum=0;
        for(int i=0;i<ratio.size();i++){
            int cap = wt[ratio[i].second];
            double t_val=ratio[i].first * cap;
            if(capacity>=cap){
                sum+=t_val;
                capacity-=cap;
            }
            else{
                sum+=((double)capacity/cap)*t_val;break;
            }
        }
        
        return sum;
    }
};


// -------------------------

// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

static bool comp(pair<int,int> &a, pair<int,int>& b){
    double r1= (double)a.first/a.second;
    double r2= (double)b.first/b.second;
    return r1>r2;
}

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<pair<int,int>> arr;
        double sum=0.0;
        for(int i=0;i<n;i++){
            arr.push_back({val[i],wt[i]});
        }
        sort(arr.begin(),arr.end(),comp);
        for(int i=0;i<n;i++){
            if(arr[i].second<=capacity){
                capacity -= (arr[i].second);
                sum += arr[i].first;
            }
            else{
                sum+= (arr[i].first/(double)arr[i].second) * capacity;
                break;
            }
        }
        return sum;
        
    }
};
