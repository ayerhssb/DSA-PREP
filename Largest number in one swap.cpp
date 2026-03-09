class Solution {
  public:
    string largestSwap(string &s) {
        int n=s.size(),maxind=-1;
        char maxdigit ='0';
        int r=-1,l=-1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]>maxdigit){maxind=i;maxdigit = s[i];}
            else if(s[i]<maxdigit){l=i;r=maxind;}
        }
        if(l==-1){return s;}
        swap(s[l],s[r]);
        return s;
    }
};
