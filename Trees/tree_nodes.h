#ifndef TREE_NODES_H
#define TREE_NODES_H

#include <stdio.h>

typedef struct tree_node TreeNode;
struct tree_node {
    int data;
    TreeNode *left, *right;
};

TreeNode*
new_node(int data, TreeNode* left, TreeNode* right);

TreeNode* 
insert(TreeNode* root, int data); //Implementando como arvore de busca de inteiros

TreeNode*
search(TreeNode* root, int data);

void
print_tree(TreeNode* root);

endif //TREE_NODES_H
