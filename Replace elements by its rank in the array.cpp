class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        
        //USING VECTOR

        // vector<int> ans(N,0);
        // vector<pair<int, int>> vec;
        // for(int i=0;i<arr.size();i++){
        //     vec.push_back({arr[i],i});
        // }
        // sort(vec.begin(),vec.end());
        // int j=1;
        // for(int i=0;i<arr.size();i++){
        //     int curr = vec[i].second;
        //     if(i>0 && vec[i].first != vec[i-1].first){j++;}
        //     ans[curr] = j;
        // }
        
        // return ans;
        
        //USING MINHEAP
        // min-heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i = 0; i<N; i++){
            pq.push({arr[i],i});  // element, index
        }
        
        vector<int> ans(N,0);
        
        int rank = 0;
        int prev = 0;
        
        while(!pq.empty()){
            auto ele = pq.top(); pq.pop();
            
            if(ele.first != prev) {
                rank++;
                prev = ele.first;
            } 
            ans[ele.second] = rank;
        }
        
        return ans;
    }

};
