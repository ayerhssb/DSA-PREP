class Solution {
public:
    int sumapple(vector<int>& apple){
        int sum=0;
        for(auto it:apple){
            sum+=it;
        }
        return sum;
    }
    int sumcapacity(vector<int>& capacity){
        int sum=0;
        for(auto it:capacity){
            sum+=it;
        }
        return sum;
    }
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sumApples = sumapple(apple);
        // int sumCapacity = sumcapacity(capacity);
        int cnt=0;
        // if(sumCapacity<sumApples){return 0;}
        sort(capacity.begin(),capacity.end(), greater<int>());
        for(auto it:capacity){
            sumApples-=it;cnt++;
            if(sumApples<=0){break;}
        }
        return cnt;
    }
};
