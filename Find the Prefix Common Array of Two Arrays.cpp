class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        //Optimal Approach (O(N) Time Complexity)
        int cnt=0, n=A.size();
        vector<int> freq(n+1,0);
        vector<int> res;
        for(int i=0;i<n;i++){
            freq[A[i]]++;
            if(freq[A[i]]==2){cnt++;}
            freq[B[i]]++;
            if(freq[B[i]]==2){cnt++;}

            res.push_back(cnt);
        }

        return res;
    }
};
