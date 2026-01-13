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
