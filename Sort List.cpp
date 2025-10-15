//NOOB SOLUTION
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
    ListNode* sortList(ListNode* head) {
        if(!head){return nullptr;}
        vector<int> val;
        ListNode* temp=head;
        while(temp!=nullptr){
            val.push_back(temp->val);
            temp=temp->next;
        }
        sort(val.begin(), val.end());
        ListNode *dummy = new ListNode(-1);
        ListNode* temp1=new ListNode(val[0]);
        dummy->next=temp1;
        for(int i=1;i<val.size();i++){
            ListNode* newnode=new ListNode(val[i]);
            temp1->next = newnode;
            temp1= temp1->next;
        }
        temp1->next=nullptr;
        return dummy->next;
    }
};
