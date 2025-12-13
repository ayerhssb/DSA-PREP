class Solution {
public:
    bool ok_bl(string &arr){
        if(arr=="electronics"|| arr=="grocery" || arr=="pharmacy" || arr=="restaurant"){
            return true;
        }
        return false;
    }

    bool is_ok_code(string str){
        if(str==""){return false;}
        for(int i=0;i<str.size();i++){
            char ch=str[i];
            if(!iswalnum(ch) && ch!='_'){return false;}
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> res;
        vector<pair<string,string>> ans;
        int n=code.size();
        for(int i=0;i<n;i++){
            if(isActive[i]){
                if(ok_bl(businessLine[i])){
                    if(is_ok_code(code[i])){
                        ans.push_back({code[i],businessLine[i]});
                    }
                }
            }
        }

        const map<string, int> mpp = {{"electronics",0}, {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}};
        sort(ans.begin(),ans.end(),[&mpp](const pair<string,string> &a, const pair<string, string> &b){
            int orderA=mpp.at(a.second);
            int orderB=mpp.at(b.second);
            if(orderA != orderB){
                return orderA<orderB;
            }
            return a.first<b.first;
        });
        for(auto it:ans){
            res.push_back(it.first);
        }
        return res;
    }
};
