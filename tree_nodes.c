#include <stdio.h>

typedef struct tree_node TreeNode;
struct tree_node {
    int data;
    TreeNode *left, *right;
};

TreeNode*
new_node(int data, TreeNode* left, TreeNode* right){
    TreeNode* new_root;

    new_root->data  = data;
    new_root->left  = left;
    new_root->right = right;
    
    return new_root;
}

TreeNode* 
insert(TreeNode* root, int data){ //Implementando como arvore de busca de inteiros

    if(root == NULL){
        TreeNode* node = new_node(data,NULL,NULL);
        root = node;

        return root;
    }

    if(data >= root->data){
        root->right = insert(root->right,data);
    }
    else{
        root->left = insert(root->left, data);
    } 

    return root;
}

TreeNode*
search(TreeNode* root, int data){
    if(root == NULL){
        return NULL;
    }

    if(data == root->data)
        return root;
    else{
        if(data > root->data){
          root = search(root->right, data);
        }
        else{
          root = search(root->left, data);
        }
    }
    
    return root;
} 

void
print_tree(TreeNode* root){
    if (root == NULL)
        return;

    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);

}
