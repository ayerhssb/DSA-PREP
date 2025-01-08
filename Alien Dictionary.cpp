class Solution {
  public:
    string findOrder(vector<string> dict, int k) {
        vector<int> adj[k];
        vector<int> indegree(k,0);
        queue<int> q;
        vector<int> temp;
        string ans="";
        
        //build adjecency list
        for(int i=0;i<dict.size()-1;i++){
            int n=dict[i].size(),m=dict[i+1].size(),j=0;
            if(n>m){swap(n,m);}
            while(j<n){
                if(dict[i][j]==dict[i+1][j]){
                    j++;
                }
                else{
                    adj[(dict[i][j]-'a')].push_back(dict[i+1][j]-'a');
                    break;
                }
            }
        }
        
        //build indegree array
        for(int i=0;i<k;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            temp.push_back(front);
            
            for(auto it: adj[front]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        if(temp.size()!=k){return "";}
        for(int i=0;i<temp.size();i++){
            ans= ans+ char(temp[i]+'a');
        }
        return ans;
    }
};
