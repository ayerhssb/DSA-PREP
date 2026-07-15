#include <bits/stdc++.h>
using namespace std;

/*
class Node {
    public:
        int data;
        Node* next;
        
        Node() : data(0), next(nullptr) {}
        Node(int data) : data(data), next(nullptr) {}
        Node(int data, Node* next) : data(data), next(next) {}
};
*/

class solution {
public:
    Node* deleteKthFromMiddle(Node* head, int k) {
        Node* slow=head; Node* fast=head;
        int cnt=0;
        while(fast&&fast->next){
            cnt++;
            slow=slow->next;
            fast=fast->next->next;
        }
        //cnt-k=len;
        int len=cnt-k-1;
        Node* temp=head;
        while(len){
            temp=temp->next;
            len--;
        }
        Node* del = temp->next;
        temp->next=temp->next->next;
        delete(del);
        
        return head;
    }
};
