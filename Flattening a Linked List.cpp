/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node *flatten(Node *root) {
        vector<int> arr;
        while(root){
            Node* temp=root;
            while(temp){
                arr.push_back(temp->data);
                temp=temp->bottom;
            }
            root=root->next;
        }
        sort(arr.begin(),arr.end());
        // for(auto it:arr){cout<<it<<" ";}
        Node* dummy = new Node(-1);
        Node* temp=dummy;
        int i=0;
        while(i<arr.size()){
            Node* temp1= new Node(arr[i]);
            temp->bottom = temp1;
            temp = temp1;
            i++;
        }
        return dummy->bottom;
    }
};
