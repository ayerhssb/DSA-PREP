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
