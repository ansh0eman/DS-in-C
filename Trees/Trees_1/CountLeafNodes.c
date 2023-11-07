// • Every time a node is visited, check whether the right and left link of that node is
// NULL. If yes, count is incremented.
/*counting number of leaf nodes using inorder technique*/
int count_leafnodes( Nodeptr root){
    static int count = 0;
    if(root!=NULL){
     if(root->lchild==NULL && root->rchild==NULL)
     count++;
     count_leafnodes(root->lchild);
     count_leafnodes(root->rchild);
    }
    return count;
}
// Counting the number of leaf nodes in a
// binary tree
