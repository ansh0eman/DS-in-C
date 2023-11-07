#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the height of a binary tree
int height(struct Node* root) {
    if (root == NULL) {
        return -1; // Height of an empty tree is -1
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Height of the tree is the maximum height of the left and right subtrees + 1 (for the root)
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

// Main function
int main() {
    // Create a sample binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->right->right = createNode(6);

    // Find and print the height of the tree
    printf("Height of the binary tree: %d\n", height(root));

    return 0;
}

/*recursive function to find the height of a tree
int height (NODEPTR root)
{
if(root==NULL)
return 0;
return( 1+ max(height (root→lchild), height(root→rchild)));
}
//Max function
int max(int a, int b){
if(a>b)
return a;
else
return b;
}
*/
