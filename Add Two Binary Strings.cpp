#include<bits/stdc++.h>
using namespace std;


class solution {
public:
    string addTwoBinaryStrings(string s1, string s2) {
        int n1=s1.size(), n2 = s2.size(); string str="";
        int l1=n1-1, l2=n2-1; char carry='0';
        while(l1>=0 && l2>=0){
            if(s1[l1]=='0'&&s2[l2]=='0'){
                if(carry=='1'){
                    str+='1';
                    carry='0';
                }
                else {str+='0';carry='0';}
            }
            else if(s1[l1]=='1'&&s2[l2]=='1'){
                if(carry=='1'){
                    str+='1'; carry='1';
                }else{
                    str+='0'; carry='1';
                }
            }
            else{
                if(carry=='1'){
                    str+='0'; carry='1';
                }
                else{
                    str+='1'; carry='0';
                }
            }
            l1--;l2--;
        }
        
        while(l1>=0){
            if(s1[l1]=='0'){
                if(carry=='1'){str+='1'; carry='0';}
                else{str+='0';}
            }
            else{
                if(carry=='1'){str+='0'; carry='1';}
                else{
                    str+='1';
                }
            }
            l1--;
        }
        
        while(l2>=0){
            if(s2[l2]=='0'){
                if(carry=='1'){str+='1'; carry='0';}
                else{str+='0';}
            }
            else{
                if(carry=='1'){str+='0'; carry='1';}
                else{
                    str+='1';
                }
            }
            l2--;
        }
        
        if(carry=='1'){
            str+='1';
        }
        
        reverse(str.begin(), str.end());
        
        return str;
    }
};
