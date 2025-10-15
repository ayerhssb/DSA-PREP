//rev - 40mins :/

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
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        // ListNode* head1=l1;
        // ListNode* head2=l2;
        ListNode* dummy = new ListNode(-1) ;
        ListNode* temp=dummy;
        int carry=0;
        while(head1 && head2){
            int sum = head1->val + head2->val+carry;
            if(sum>9){carry=1;sum=sum%10;}else{carry=0;}
            ListNode* add= new ListNode(sum);
            temp->next = add;
            temp=temp->next;
            head1=head1->next;
            head2=head2->next;
        }
        while(head1){
            int sum = head1->val+carry;
            if(sum>9){carry=1;sum=sum%10;}else{carry=0;}
            ListNode* add= new ListNode(sum);
            temp->next = add;
            temp=temp->next;
            head1= head1->next;
        }
        while(head2){
            int sum = head2->val+carry;
            if(sum>9){carry=1;sum=sum%10;}else{carry=0;}
            ListNode* add= new ListNode(sum);
            temp->next = add;
            temp=temp->next;
            head2= head2->next;
        }
        if(carry){
            ListNode* add= new ListNode(carry);
            temp->next = add;
            temp=temp->next;
        }
        temp->next=NULL;
        return dummy->next;
    }
};



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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum;
        ListNode* dummyNode = new ListNode(0);
        ListNode* curr = dummyNode;
        while (l1 && l2) {
            sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            ListNode* newnode = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = newnode;
            curr = curr->next;
        }

        while (l1) {
            sum = carry;

            sum += l1->val;
            l1 = l1->next;

            ListNode* newnode = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = newnode;
            curr = curr->next;
        }

        while (l2) {
            sum = carry;

            sum += l2->val;
            l2 = l2->next;

            ListNode* newnode = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = newnode;
            curr = curr->next;
        }

        if(carry){
            ListNode* newnode = new ListNode(carry);
            curr->next = newnode;
        }

        return dummyNode->next;
    }
};
