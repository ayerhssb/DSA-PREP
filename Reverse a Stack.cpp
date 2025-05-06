class Solution {
  public:
  void helper(stack<int> &St, int x){
      
      if(St.size()==0){
          St.push(x);
          return;
      }
      
          int temp=St.top();
          St.pop();
          helper(St,x);
          St.push(temp);
      
  }
    void Reverse(stack<int> &St) {
        if(St.size()==0){
            return;
        }
        int x=St.top();
        St.pop();
        Reverse(St);
        helper(St,x);
    }
};
