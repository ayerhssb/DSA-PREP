class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize !=0){
            return false;
        }
        map<int,int> mp;
        for(int it:hand){
            mp[it]++;
        }
        for(auto it:mp){
            if(it.second==0){
                continue;
            }
            while(it.second--){
                for(int i=0; i<groupSize;i++){
                    if(mp[it.first+i] == 0){return false;}
                    mp[it.first+i]--;
                }
            }
        }
        return true;
    }
};
