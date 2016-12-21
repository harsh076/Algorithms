#include <stdio.h>
#include <stdlib.h>

typedef struct dnode
{
    int data;
    struct dnode* prev;
    struct dnode* next;
}dnode;

int dlist_empty(dnode*);
dnode* dilst_insert(dnode*,int,int);
void dilst_print(dnode*);
int dilst_search(dnode*,int);
dnode* dilst_delete(dnode*,int);
dnode* dilst_accsess(dnode*,int);

int dilist_empty(dnode* head)
{
    if(head == NULL)
    return 1;
    else
    return 0;
}

dnode* dilst_insert(dnode* head, int data, int pos)
{
    if(dilist_empty(head))
    {
        dnode* temp = (dnode*)malloc(sizeof(dnode));
        temp->data = data;
        temp->prev = NULL;
        temp->next = NULL;
        head = temp;
    }

    return head;
}
