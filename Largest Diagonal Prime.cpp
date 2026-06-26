#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    bool isPrime(int num){
        int sroot = sqrt(num);
        for(int i=1;i<=sroot;i++){
            if(num%i==0 && i!=1){
                return false;
            }
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& mat) {
        int n=mat.size(), maxi=0;
        //main diagonal
        for(int i=0;i<n;i++){
            if(isPrime(mat[i][i])){
                maxi=max(maxi,mat[i][i]);
            }
        }
        //secondary diagonal
        for(int i=0;i<n;i++){
            if(isPrime(mat[i][n-1-i])){
                maxi=max(maxi,mat[i][n-1-i]);
            }
        }
        return maxi;
    }
};
