void Delete(Nodeptr *root, int item) {
    Nodeptr parent, cur;
    Nodeptr q, succ;

    // Check if the tree is empty
    if (*root == NULL) {
        printf("Empty Tree\n");
        return;
    }

    // Traverse the tree until the item is found or the entire tree is traversed
    parent = NULL;
    cur = *root;
    while (cur && (cur->data != item)) {
        parent = cur;
        if (item < cur->data)
            cur = cur->lchild;
        else
            cur = cur->rchild;
    }

    // If the item is not found
    if (cur == NULL) {
        printf("Item Not Found\n");
        return;
    }

    // Item found, and check for case 1
    if (cur->lchild == NULL) {
        // Node to be deleted has an empty left subtree
        q = cur->rchild; // Get the address of the right subtree
    } else if (cur->rchild == NULL) {
        // Node to be deleted has an empty right subtree
        q = cur->lchild; // Get the address of the left subtree
    } else {
        // Interior node - find inorder successor (smallest element in the right subtree)
        parent = cur;
        succ = cur->rchild; // Get the address of the right child of the node to be deleted
        while (succ->lchild) {
            // Move to the leftmost node of succ
            parent = succ;
            succ = succ->lchild;
        }
        // Exchange the data of current and succ
        cur->data = succ->data;
        cur = succ;
        q = cur->rchild;
    }

    // Update the parent's link or root link
    if (parent == NULL) {
        free(cur);
        *root = q;
        return;
    }

    if (cur == parent->lchild) {
        parent->lchild = q;
    } else {
        parent->rchild = q;
    }

    free(cur);
}
