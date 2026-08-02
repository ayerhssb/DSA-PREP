#include <bits/stdc++.h>
using namespace std;

/*
class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(NULL){}
};
*/

class solution {
public:
    Node* removeLoop(Node* head) {
        Node* slow=head; Node* fast=head;
        if(slow!=nullptr)slow=slow->next;
        if(fast->next!=nullptr)fast=fast->next->next;
        while(fast!=slow){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node* temp=fast;
        slow=head;
        while(fast!=slow){
            slow=slow->next;
            temp=fast;
            fast=fast->next;
        }
        temp->next=nullptr;
        return head;
    }
};
