#include <functional>

class Solution {
public:
    void incby1(vector<int> &arr){
        for(int i=0;i<arr.size();i++){
            arr[i]+=1;
        }
    }
    void inconline(vector<int> &ans, vector<long long> &offline, int time){
        for(int i=0;i<offline.size();i++){
            if(offline[i]<=time){
                ans[i]+=1;
            }
        }
    }
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        sort(events.begin(),events.end(),[](const vector<string> &a, const vector<string>& b){
            if(a[1]!=b[1]){
                return stoi(a[1])<stoi(b[1]);
            }
            
            return a[0]>b[0];
        });
        for(int i=0;i<events.size();i++){
            cout<<events[i][0]<< " "<< events[i][1]<< " "<<events[i][2]<<endl;
        }
        vector<int> ans(n,0);
        vector<long long> offline(n,0);
        for(int i=0;i<events.size();i++){
            if(events[i][0]=="OFFLINE"){
                int id = stoi(events[i][2]);
                int time = stoi(events[i][1]);
                offline[id]=time+60;
            }
            else{
                if(events[i][2]=="ALL"){
                    incby1(ans);
                }
                else if(events[i][2]=="HERE"){
                    int time = stoi(events[i][1]);
                    inconline(ans, offline, time);
                }
                else{
                    int k=2;
                    int len=events[i][2].size();
                    string str = events[i][2];
                    stringstream ss(str);
                    string s;
                    while(getline(ss,s,' ')){
                        string str1="";
                        for(int i=2;i<s.size();i++){
                            str1+=s[i];
                        }
                        int idx = stoi(str1); 
                        ans[idx]+=1;
                    }
                }
            }
        }
        return ans;
    }
};
