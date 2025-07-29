// constant space complexity: tc-> O(N)

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
    int lengthOfCycle(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(1){
            if(!fast->next || !slow->next){return 0;}
            slow=slow->next;
            fast = fast->next->next;
            if(slow==fast){
                int cnt=1;
                fast=fast->next;
                while(fast!=slow){
                    fast=fast->next;
                    cnt++;
                }
                return cnt;
            }
        }
        return 0;
    }
};


// O(N) space complexity.... tc-> O(N)

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
    int lengthOfCycle(Node* head){
        unordered_map<Node*, int> mpp;
        Node* temp = head;
        int cnt=1;
        while(1){
            if(!temp){return 0;}
            if(mpp.find(temp)!=mpp.end()){
                return cnt - mpp[temp];
            }
            mpp[temp] = cnt;
            cnt++;
            temp = temp->next;
        }
        return 0;
    }

};



