#include <limits.h>

pair<int, int> El(vector<int> &boards){
    int maxi= INT_MIN , summ=0;
    for(int i=0;i<boards.size();i++){
        if(boards[i]>maxi) maxi=boards[i];
        summ+=boards[i];
    }
    return {maxi,summ};
}

int painter(vector<int> &boards, int mid){
    int sum=0,painters=1;
    for(int i=0;i<boards.size();i++){
        if(sum+boards[i]<=mid){
            sum+=boards[i];
        }
        else{
            sum=boards[i];
            painters++;
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int low=El(boards).first,high=El(boards).second;
    while(low<=high){
        int mid=(low+high)>>1;
        if(painter(boards,mid)<=k){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
