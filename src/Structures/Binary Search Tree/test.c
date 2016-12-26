#include<stdio.h>
#include<stdlib.h>
#include"bst.h"

int main()
{
    bst* A = NULL;
    A = bst_insert(A,8);
    A = bst_insert(A,7);
    A = bst_insert(A,19);
    A = bst_insert(A,18);
    A = bst_insert(A,56);
    A = bst_insert(A,2);
    A = bst_insert(A,76);
    A = bst_insert(A,6);
    A = bst_insert(A,55);
    bst_treverse(A);

    printf("\n");
    bst* S = tree_search(A,18);
    S = bst_successor(A,S);
    printf("%6d",S->data);

    printf("\n");
    S = tree_search(A,18);
    S = bst_predecessor(A,S);
    printf("%6d",S->data);

    return 0;
}
