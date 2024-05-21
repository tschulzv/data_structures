#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    Tree left;
    Tree right;
} Node;

typedef Node* Tree;

Tree createNode(int val){
    Tree node = (Tree)malloc(sizeof(Node));
    if (node == NULL) return NULL;
    node -> val = val;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

void addNode(Tree root, int val){
    if (root == NULL){ // creating a new tree
        root = createNode(val);
    }
    // if tree exists
    if (root->val > val){
        addNode(root->left, val); // recursively insert in left branch
    } else if(root->val < val){
        addNode(root->right, val); // recursively insert in right branch
    }
}

void delete(Tree root, int val){
    
}


int main()
{
    return 0;
}
