void iterativePreorder(struct Node* root){  //Visiting Left Right
    if(root==NULL){
        printf("no tree\n");
        return;
    }
    struct Stack* stack =createstack();
    push(stack,root);

    while(!isEmpty(stack)){
        struct Node* current = pop(stack);
        printf("%d ",current->data);
        if(current->right){
            push(stack, current->right);
        }
        if(current->left){
            push(stack,current->left);
        }
    }
}

void preorder(struct Node*root){
    if(root){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node*root){
    if(root){
        preorder(root->left);
        printf("%d ", root->data);
        preorder(root->right);
    }
}

void postorder(struct Node*root){
    if(root){
        preorder(root->left);
        preorder(root->right);
        printf("%d ", root->data);
    }
}

void iterativeInorder(struct Node* root){ //LVR
    struct Stack* stack = createstack();
    struct Node* current = root;
    while(current!=NULL || isEmpty(stack)){
        while(current!=NULL){
            push(stack ,current);
            current = current->left;
        }
        current = pop(stack);
        printf("%d ",current->data);

        current = current->right;
    }
}

void iterativePostorder(struct Node* root){ //LRV
    struct Node* current = root;
    struct Stack* stack = createstack();

    while(current != NULL || isEmpty(stack)){
            
    }
}