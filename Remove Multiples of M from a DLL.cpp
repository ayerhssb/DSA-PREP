#include <bits/stdc++.h>
using namespace std;
/*
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};*/
class solution{
    public:
        Node* deleteNodesDivisibleByM(Node* head, int m) {
            if(!head){return head;}
            while((head->data)%m==0){
                if(!head->next){return nullptr;}
                head->next->prev=nullptr;
                Node* curr = head;
                head=head->next;
                delete(curr);
            }
            if(!head){return head;}
            Node* temp=head;
            while(temp){
                if(temp->data % m==0){
                    Node* curr=temp;
                    if(!curr->next){curr->prev->next=nullptr;delete(curr);}
                    else{curr->prev->next = curr->next;
                        curr->next->prev=curr->prev;
                        curr->next=nullptr;
                        delete(curr);
                    }
                }
                temp=temp->next;
            }
            return head;
        }
};
