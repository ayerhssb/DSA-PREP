class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        if(s1.size()!=s2.size()){return false;}
        string str=s1+s1;
        if(str.find(s2)!=string::npos){return true;}
        return false;
        //brute approach
        // int n=s1.size();
        // if(s1.size()!=s2.size()){return false;}
        // for(int i=0;i<n;i++){
        //     string str = s1.substr(1,s1.size()-1)+s1[0];
        //     s1=str;
        //     if(s1==s2){return true;}
        // }
        // return false;
    }
};
