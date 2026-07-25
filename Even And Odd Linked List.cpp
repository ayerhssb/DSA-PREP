#include<bits/stdc++.h>
using namespace std;

/*
class Node {
    public:
        int data;
        Node* next;
    public:
        Node(int value, Node* address){
            data = value;
            next = address;
        }
    public:
        Node(int value){
            data = value;
            next = NULL;
        }
    public:
        Node(){
            data = 0;
            next = NULL;
        }
};
*/

class solution {
public:
   Node* evenAndOdd(Node* head) {
        Node* dummy = new Node(-1);
        Node* temp=dummy;
        Node* temp1=head;
        while(temp1 && temp1->next){
            Node* newnode= new Node(temp1->data);
            temp->next=newnode;
            temp=newnode;
            temp1=temp1->next->next;
        }
        if(temp1){
            Node* newnode= new Node(temp1->data);
            temp->next=newnode;
            temp=newnode;
        }
        temp1=head->next;
        while(temp1 && temp1->next){
            Node* newnode= new Node(temp1->data);
            temp->next=newnode;
            temp=newnode;
            temp1=temp1->next->next;
        }
        if(temp1){
            Node* newnode= new Node(temp1->data);
            temp->next=newnode;
            temp=newnode;
        }
        
        return dummy->next;
    }

};
