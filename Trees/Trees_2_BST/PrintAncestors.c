bool printAncestors(struct node *root, int target) {
    // If the current node is NULL, return false (base case)
    if (root == NULL)
        return false;

    // If the current node's data matches the target, print the data and return true
    if (root->data == target) {
        printf("%d ", root->data);
        return true;
    }

    // Recursively check in the left and right subtrees
    // If the target is found in either subtree, print the current node's data
    // and return true to indicate that the target is found in the current subtree
    if (printAncestors(root->left, target) || printAncestors(root->right, target)) {
        printf("%d ", root->data);
        return true;
    }

    // If the target is not found in the current subtree, return false
    return false;
}
