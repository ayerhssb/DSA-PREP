#include <bits/stdc++.h>
using namespace std;

/*
class Node {
    public:
        int data;
        Node* next;
        
        Node(): data(0), next(nullptr) {}
        Node(int data) : data(data), next(nullptr) {}
        Node(int data, Node* next) : data(data), next(next) {}
};
*/

class solution {
public:
    Node* deleteNAfterMNodes(Node* head, int m, int n) {
        if(head==nullptr){return nullptr;}
        int m1=m, n1=n;
        Node* temp=head;
        while(temp){
            Node* prev;
            while(temp&& m1--){
                prev=temp;
                temp=temp->next;
            }
            while(temp&& n1--){
                Node* curr = temp;
                temp=temp->next;
                delete(curr);
            }
            prev->next = temp;
            m1=m, n1=n;
        }
        return head;
    }
};
