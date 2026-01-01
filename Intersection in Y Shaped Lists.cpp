/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        if(!head1 || !head2){return nullptr;}
        unordered_map<Node*, int> mpp;
        while(head1!=NULL){
            mpp[head1]++;
            head1=head1->next;
        }
        while(head2!=nullptr){
            if(mpp.find(head2)!=mpp.end()){return head2;}
            head2=head2->next;
        }
        return head1;
    }
};
