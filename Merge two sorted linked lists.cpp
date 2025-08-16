//Revision:

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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr= dummy;

        while(list1 && list2){
            if(list1->val < list2->val){
                curr->next = list1;
                list1=list1->next;
            }else{
                curr->next = list2;
                list2=list2->next;
            }
            curr= curr->next;
        }

        while(list1){
            curr->next = list1;
            list1=list1->next;
            curr=curr->next;
        }
        while(list2){
            curr->next = list2;
            list2=list2->next;
            curr=curr->next;
        }
        return dummy->next;
    }
};

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node* dummyNode = new Node(0);
        dummyNode->data = -1;
        Node* temp = dummyNode;
        // temp->next = NULL;
        
        while(head1!=NULL && head2 !=NULL){
            if(head1->data < head2->data){
                temp->next = head1;
                temp=head1;
                head1 = head1->next;
            }
            else{
                temp->next = head2;
                temp=head2;
                head2 = head2->next;
            }
        }
        
        if(head1!=NULL){
            temp->next = head1;
        }
        if(head2!=NULL){
            temp->next = head2;
        }
        
        return dummyNode->next;
    }
};
