#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    bool isArraySpecial(int n, vector<int>& values) {
      int odd=1;
      if(values[0]%2==0){odd=0;}
      for(int i=1;i<values.size();i++){
          int opp=values[i]%2;
          if( (!odd) != opp){
              return false;
          }
          odd = (!odd);
      }
      return true;
    }
};
