#include <stdio.h>
#include <stdlib.h>
#include "../Pilha/pilha_encadeada_void.c"

typedef struct tree_node TreeNode;
struct tree_node {
int data;
TreeNode *left, *right;
};

TreeNode*
new_node(int data, TreeNode* left, TreeNode* right){
TreeNode* new_root = malloc(sizeof(TreeNode));

new_root->data  = data;
new_root->left  = left;
    new_root->right = right;
    
    return new_root;
}

TreeNode* 
insert(TreeNode* root, int data){
//Implementing as a integer search binary tree [RECURSIVALY]

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

//TreeNode*
//insert_itera_pilha(TreeNode* root, int data){

TreeNode*
insert_itera(TreeNode* root, int data){
//Implementing as a integer search binary tree [ITERATIVALY]
    TreeNode* tree_root = root;
    TreeNode* node = new_node(data,NULL,NULL);

    if(root==NULL){
        root=node;
        return root;
    }

    while( (tree_root!=NULL)  ){
        if(data < tree_root->data){
           if(tree_root->left==NULL){
               tree_root->left=node;
               break;
           }
           tree_root = tree_root->left; 
           continue;
        }
        else{
           if(tree_root->right==NULL){
               tree_root->right=node;
               break;
           }
           tree_root = tree_root->right;
           continue;
        }
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

TreeNode*
search_itera(TreeNode* root, int data){
    Pilha *pilha = pilha_nova();
    TreeNode* handler = root;
    
    while(handler!=NULL && !vazia(pilha)){
        while(handler->left!=NULL){
           if(handler->data == data) 
               return handler;
           pilha_empilha(pilha, handler);
           handler=handler->left;
        }
        if(handler->data == data) 
            return handler;
       
        if(handler->right == NULL){
            handler = pilha_desempilha(pilha)->right;
        }
        else
            handler = handler->right;
    }

    return NULL;
}


void
print_tree(TreeNode* root){
    if (root == NULL){
        printf("[NULL] \n");
        return ;
    }

    print_tree(root->left);
    printf("[%d] \n", root->data);
    print_tree(root->right);

}
