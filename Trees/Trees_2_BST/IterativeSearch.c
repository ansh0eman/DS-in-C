struct Node * itersearch(struct Node * root, int key)
{
    while (root) {
        if (key == root->data) 
          return root;
        if (key < root->data)
          root = root->lchild;
        else 
          root = root->rchild;
    }
    return NULL;
}
