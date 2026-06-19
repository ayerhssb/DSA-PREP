// forgot:

#include <bits/stdc++.h>
using namespace std;
/*
class Node {
public:
    int data;
    Node* next;
    Node(int data, Node* next) : data(data), next(next) {}
    Node(int data) : data(data), next(nullptr) {}
};
*/
class solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {
        
        priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
        for(int i=0;i<arr.size();i++){
            if(!arr[i]){continue;}
            pq.push({arr[i]->data, arr[i]});
        }
        Node* dummy= new Node(-1); Node* temp=dummy;
        while(!pq.empty()){
            int top_data = pq.top().first;
            Node* top_val = pq.top().second;
            pq.pop();
            Node* newnode = new Node(top_data);
            temp->next=newnode;
            temp=newnode;
            if(top_val->next){
                pq.push({top_val->next->data , top_val->next});
            }
        }
        return dummy->next;
    }
};


//revision:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Comp{
public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }

};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*>, Comp> pq;
        for(ListNode* head: lists){
            if(head!=nullptr)pq.push(head);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* curr= dummy;
        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();
            curr->next=top;
            // curr=top;
            if(top->next!=nullptr){
                pq.push(top->next);
            }
            top=top->next;
            curr=curr->next;
        }
        return dummy->next;
    }
};


/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;
        for(int i=0;i<arr.size();i++){
            if(arr[i]){
                pq.push({arr[i]->data, arr[i]});
            }
        }
        while(!pq.empty()){
            Node* curr = pq.top().second;
            pq.pop();
            temp->next = curr;
            temp = temp->next;
            if(curr->next){
                pq.push({curr->next->data, curr->next});
            }
        }
        temp->next = nullptr;
        
        return dummyNode->next;
    }
};
