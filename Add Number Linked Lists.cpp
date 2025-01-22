/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
    Node* reverse(Node* head){
        Node* prev=NULL;
        Node* curr=head;
        Node* next=NULL;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        Node* head1 = reverse(num1);
        Node* head2 = reverse(num2);
        int carry=0,sum;
        Node* dummyNode = new Node(0);
        Node* curr = dummyNode;
        while(head1 !=NULL && head2!=NULL){
            sum = carry;
            if(head1){
                sum += head1->data;
                head1=head1->next;
            }
            if(head2){
                sum += head2->data;
                head2=head2->next;
            }
            
            Node* newnode = new Node(sum%10);
            carry = sum/10;
            curr->next = newnode;
            curr= curr->next;
        }
        while(head1){
            sum = carry;
            sum += head1->data;
            head1=head1->next;
            
            Node* newnode = new Node(sum%10);
            carry = sum/10;
            curr->next = newnode;
            curr= curr->next;
        }
        while(head2){
            sum = carry;
            sum += head2->data;
            head2=head2->next;
            
            Node* newnode = new Node(sum%10);
            carry = sum/10;
            curr->next = newnode;
            curr= curr->next;
        }
        
        if(carry){
            Node* newnode = new Node(carry);
            curr->next = newnode;
        }
        Node* temp = dummyNode->next;
        dummyNode->next=NULL;
        Node* sumlist = reverse(temp);
        
        while(sumlist->data ==0){
            sumlist=sumlist->next;
        }
        
        return sumlist;
    }
};
