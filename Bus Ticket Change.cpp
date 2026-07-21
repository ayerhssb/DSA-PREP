//again:

#include<bits/stdc++.h>
using namespace std;
class solution {
public:
    bool movieTicketCounter(vector<int>& tickets) {
        int fifty=0, hundred=0, twohundred=0, n=tickets.size();
        for(int i=0;i<n;i++){
            if(tickets[i]==100){
                if(fifty==0){
                return false;}
                else{
                    hundred++;
                    fifty--;
                }
            }
            else if(tickets[i]==200){
                if(hundred>=1 && fifty>=1){
                    twohundred++; fifty--; hundred--;
                }
                else if(fifty>=3){
                    twohundred++; fifty-=3;
                }
                else {
                    return false;
                }
            }
            else{
                fifty++;
            }
        }
        return true;
    }
};
// -------------------------------------------------------------------------------------------------

class Solution {
  public:
    bool canServe(vector<int> &arr) {
        int five=0,ten=0,twenty=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==5){five+=1;}
            else if(arr[i]==10){
                if(!five){return false;}
                ten+=1;five-=1;
            }
            else{
                if(!five){return false;}
                if(!ten){
                    if(five<3){return false;}
                }
                twenty+=1;
                
                if(ten){
                    ten-=1;five-=1;
                }
                else{
                    five-=3;
                }
            }
        }
        return true;
    }
};
