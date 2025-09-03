//Revision:

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //using hashmap
        // result will be max(((n+1)*(f-1)+X), size)
        int f=0,X=0, size=tasks.size();
        unordered_map<char, int> mpp;
        for(auto it:tasks){mpp[it]++; if(f<mpp[it]){f=mpp[it];}}
        for(auto it:mpp){if(it.second==f)X++;}
        int ans = (n+1)*(f-1) + X;
        return max(ans,size);
    }
};

//first time
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        int interval;
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        sort(freq.begin(),freq.end());
        int maxval = freq[25]-1;
        int idle= (maxval)*n;
        for(int i=24;i>=0;i--){
            if(freq[i]==0){
                break;
            }
            idle = idle - min(maxval,freq[i]);
        }

        if(idle>0){
            interval = tasks.size()+idle;
        }
        else{
            interval=tasks.size();
        }

        return interval;
    }
};
