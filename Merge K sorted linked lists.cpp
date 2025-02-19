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
