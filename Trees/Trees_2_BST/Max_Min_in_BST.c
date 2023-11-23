struct Node * Max(struct Node * root){
    if (root){
        return Max(root->right); // Recursively traverse to the right subtree
    }
    return NULL; // Return NULL if the tree is empty
}

struct Node * Min(struct Node * root){
    if (root){
        return Min(root->left); // Recursively traverse to the left subtree
    }
    return NULL; // Return NULL if the tree is empty
}
