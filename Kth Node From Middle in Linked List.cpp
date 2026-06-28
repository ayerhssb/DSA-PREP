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
    Node* findKthFromMiddle(Node* head, int k) {
        if(!head){return nullptr;}
        int cnt=0;
        Node* fast=head; Node* slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            cnt++;
        }
        // n/2+1 --> middle -k
        int len = cnt-k;
        Node* temp=head;
        while(len--){
            temp=temp->next;
        }
        return temp;
    }
};
