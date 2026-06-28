#include <bits/stdc++.h>
using namespace std;

/*
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        prev = next = NULL;
    }
};
*/

class solution {
  public:
  vector<int> toArray(Node* node) { 
    //   if(!node){return nullptr;}
    vector<int> arr;
    Node* temp=node;
    stack<Node*> st; stack<Node*> st1;
    while(temp){
        st.push(temp);
        temp=temp->prev;
    }
    while(!st.empty()){
        arr.push_back(st.top()->data);
        st.pop();
    }
    temp=node->next;
    while(temp){
        st.push(temp);
        temp=temp->next;
    }
    while(!st.empty()){
        st1.push(st.top());
        st.pop();
    }
    while(!st1.empty()){
        arr.push_back(st1.top()->data);
        st1.pop();
    }
    return arr;
  }
};
