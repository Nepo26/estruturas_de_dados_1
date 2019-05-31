#include "tree_nodes.c"
#include <stdio.h>
#include <assert.h>

void main(){
    int qnt, val, qu, i;
    TreeNode* tree_root = NULL;
   
    printf("Quantity of elements: ");
    scanf("%d",&qnt);

    for(i=0; i<qnt; i++){
        scanf("%d",&val);
        tree_root = insert_itera(tree_root,val);
//        tree_root = insert(tree_root,val);

    }
    
    printf("\nFull Tree:");
    print_tree(tree_root);
    
    printf("\nSearching for node :");
    scanf("%d",&qu);
    
    if(search(tree_root, qu) == NULL)
        printf("\nThe node was not found !\n");
    else{
        printf("\nThe node was found, and here is its tree:\n");
        print_tree(search(tree_root, qu));
    }
}
