class Solution {
  public:
  stack<pair<int,int>> st;
  int mini = INT_MAX;
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        mini=min(x,mini);
        st.push({x,mini});
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(st.empty()){
            return;
        }
        st.pop();
        if(st.empty()){
            mini= INT_MAX;
        }
        else{
            mini = st.top().second;
        }
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(st.empty()){
            return -1;
        }
        return st.top().first;
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(st.empty()){
            return -1;
        }
        return mini;
    }
};
