class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int> ans(2);int counter=0, score=0;
        for(int i=0;i<events.size();i++){
            if(counter==10){break;}
            if(events[i]=="W"){
                counter++;
            }
            else if(events[i]=="WD" ||events[i]=="NB"){
                score++;
            }
            else{
                score+=stoi(events[i]);
            }
        }
        ans[0]=score; ans[1]=counter;
        return ans;
    }
};©leetcode
