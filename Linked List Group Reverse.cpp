class Solution {
    
  public:
  
    Node* getkthNode(Node* temp, int k){
        k--;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node *reverseKGroup(Node *head, int k) {
        Node* temp = head;
        Node* prevNode = NULL;
        
        while(temp!=NULL){
            Node* kthNode = getkthNode(temp,k);
            
            if(kthNode==NULL){
                Node* last_remaining = reverse(temp);
                prevNode->next = last_remaining;
                return head;
            }
            Node* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverse(temp);
            if(temp==head){
                head=kthNode;
            }
            else{
                prevNode->next= kthNode;
            }
            prevNode = temp;
            temp=nextNode;
        }
        
        return head;
        
        // if(!head || !head->next) return head;

        // Node *prev = NULL;
        // Node *curr = head;
        
        // int it = 0;
        // while(curr && it < k){
        //     Node *next = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = next;
        //     it++;
        // }
        
        
        // head->next = reverseKGroup(curr,k);
        // return prev;
    }
};
