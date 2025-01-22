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
