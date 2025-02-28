class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int> st;
        map<string,char> mpp = {
            {"+",'+'}, {"-",'-'},
            {"*",'*'}, {"/",'/'},
        };

        for(int i=0;i<arr.size();i++){
            if(mpp.find(arr[i])!=mpp.end()){
                    int num1=st.top();
                    st.pop();
                    int num2= st.top();
                    st.pop();
                    if(arr[i]=="*"){
                        st.push(num2*num1);
                    }
                    else if(arr[i]=="/"){
                        st.push(num2 / num1);
                    }
                    else if(arr[i]=="-"){
                        st.push(num2 - num1);
                    }
                    else{
                        st.push(num2 + num1);
                    }
            }
            else{
                st.push(stoi(arr[i]));
            }
            
        }
        
        
        return st.top();
        
    }
};
