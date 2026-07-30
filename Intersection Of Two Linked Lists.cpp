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
};
*/

class solution {
public:
    Node* intersectionOfTwoLL(Node* head1, Node* head2){
        if(!head1 || !head2){return nullptr;}
        unordered_map<Node*, int> mpp;
        Node* temp1= head1;
        while(temp1!=nullptr){
            mpp[temp1]++;
            temp1=temp1->next;
        }
        Node* temp2= head2;
        while(temp2!=nullptr){
            if(mpp.find(temp2)!=mpp.end()){
                return temp2;
            }
            temp2=temp2->next;
        }
        return nullptr;
    }

};
