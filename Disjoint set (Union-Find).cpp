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
