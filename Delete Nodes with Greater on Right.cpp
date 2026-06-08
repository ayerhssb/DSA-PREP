/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *compute(Node *head) {
        if(head==nullptr){return nullptr;}
        stack<Node*> st, st1;
        Node* temp=head;
        st.push(temp);temp=temp->next;
        while(temp!=nullptr && !st.empty()){
            while((temp!=nullptr && !st.empty())&&(temp->data) > (st.top()->data)){
                st.pop();
            }
            st.push(temp);
            temp=temp->next;
        }
        while(!st.empty()){
            st1.push(st.top());st.pop();
        }
        Node* dummy = new Node(-1);
        Node* res=dummy;
        while(!st1.empty()){
            int top=st1.top()->data;
            Node* tempp = new Node(top);
            res->next=tempp;
            res=tempp;
            tempp->next=nullptr;
            st1.pop();
        }
        res->next=NULL;
        return dummy->next;
    }
};
