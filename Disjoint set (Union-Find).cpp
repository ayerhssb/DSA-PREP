//Union By Size::


#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    int find(int node, vector<int>& parent) {
        if(parent[node]<0){
            return node;
        }
        return parent[node] = find(parent[node], parent);
    }

    void unionSize(int a, int b, vector<int>& parent) {
        int parentofa= find(a, parent);
        int parentofb = find(b, parent);
        
        if(parentofa==parentofb){
            return ;
        }
        if(parent[parentofa]< parent[parentofb]){
            parent[parentofa] += parent[parentofb];
            parent[parentofb] = parentofa;
        }
        else{
            parent[parentofb] += parent[parentofa];
            parent[parentofa] = parentofb;
        }
        
    }
};



/*Complete the functions below*/
int find(int par[], int x) {
    // add code here
    if(x==par[x]){
        return x;
    }
    
    return find(par,par[x]);
}


void unionSet(int par[], int x, int z) {
    
    // vector<int> rank(n,0);
    // add code here.
    int ulp_x= find(par,par[x]);
    int ulp_z= find(par,par[z]);
    
    if(ulp_x == ulp_z){
        return;
    }
    if(ulp_x!=ulp_z){
        par[ulp_x] = ulp_z;
    }
    
}
