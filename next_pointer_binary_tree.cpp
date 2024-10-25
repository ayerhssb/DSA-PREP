void Solution::connect(TreeLinkNode *A)
{
    // TreeLinkNode* curr=A;
    // TreeLinkNode* lft=(A)? A->left : nullptr;
    // while(curr && lft ){
    //     curr->left->next = curr->right;
    //     if(curr->next){
    //         curr->right->next = curr->next->left;
    //     }
    //     curr = curr->next;
    //     if(curr=nullptr){
    //         curr = lft;
    //         lft = curr->left;
    //     }
    // }

    if (!A)
        return;
    if (!A->left && !A->right)
        return;

    queue<TreeLinkNode *> q;
    q.push(A);
    while (!q.empty())
    {
        TreeLinkNode *parent = q.front();
        q.pop();

        if (parent->left && parent->right)
        {
            TreeLinkNode *leftchild = parent->left;
            TreeLinkNode *rightchild = parent->right;
            leftchild->next = rightchild;

            TreeLinkNode *parent_siblling = parent->next;
            if (parent_siblling)
                rightchild->next = parent_siblling->left;

            q.push(parent->left);
            q.push(parent->right);
        }
    }
}