#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
    struct bst* p;
    struct bst* l;
    struct bst* r;
    int data;
}bst;

int bst_empty(bst*);
bst* tree_search(bst*,int);
void bst_treverse(bst*);
bst* bst_insert(bst*,int);
void bst_delete(bst*,bst*);
bst* bst_transplant(bst*,bst*,bst*);
bst* bst_min(bst*,bst*);
bst* bst_max(bst*,bst*);
bst* bst_successor(bst*,bst*);
bst* bst_predecessor(bst*,bst*);

int bst_empty(bst* T)
{
    if(T == NULL)
    return 1;
    else
    return 0;
}

bst* tree_search(bst* T, int key)
{
    if((T == NULL) || (T->data == key))
    return T;
    if(key < T->data)
    return tree_search(T->l,key);
    else
    return tree_search(T->r,key);
}

void bst_treverse(bst* T)
{
    if(T != NULL)
    {
        bst_treverse(T->l);
        printf("%6d",T->data);
        bst_treverse(T->r);
    }
}

bst* bst_insert(bst* T, int key)
{
    bst* node = T;
    bst* temp = (bst*)malloc(sizeof(bst));
    temp->data = key;
    temp->p = NULL;
    temp->l = NULL;
    temp->r = NULL;
    if(bst_empty(T))
    {
        T = temp;
        return T;
    }
    while(1)
    {
        if(key <= node->data)
        {
            if(node->l == NULL)
            {
                node->l = temp;
                temp->p = node;
                return T;
            }
            node = node->l;
        }
        else
        {
            if(node->r == NULL)
            {
                node->r = temp;
                temp->p = node;
                return T;
            }
            node = node->r;
        }
    }
}

void bst_delete(bst* T, bst* x)
{
    if(x->l == NULL)
    {
        bst_transplant(T,x,x->r);
        free(x);
    }
    else if(x->r == NULL)
    {
        bst_transplant(T,x,x->l);
        free(x);
    }
    else
    {
        bst* y = bst_min(T,x->r);
        if(y->p != x)
        {
            bst_transplant(T,y,y->r);
            y->r = x->r;
            y->r->p = y;
        }
        bst_transplant(T,x,y);
        y->l = x->l;
        y->l->p = y;
        free(x);
    }
}

bst* bst_transplant(bst* T, bst* u, bst* v)
{
    if(u == T)
    {
        return NULL;
    }
    else if(u->p->l == u)
    {
        u->p->l = v;
    }
    else if(u->p->r == u)
    {
        u->p->r = v;
    }
    if(v != NULL)
    {
        v->p = u->p;
    }
}

bst* bst_min(bst* T, bst* x)
{
    if(T == NULL)
    {
        return NULL;
    }
    while(x->l != NULL)
    {
        x = x->l;
    }
    return x;
}

bst* bst_max(bst* T, bst* x)
{
    if(T == NULL)
    {
        return NULL;
    }
    while(x->r != NULL)
    {
        x = x->r;
    }
    return x;
}

bst* bst_successor(bst* T, bst* x)
{
    if(x->r != NULL)
    {
        return bst_min(T,x->r);
    }
    else
    {
        bst* y = x->p;
        while(y != NULL)
        {
            if(y->l == x)
            {
                return y;
            }
            x = y;
            y = y->p;
        }
    }
    return NULL;
}

bst* bst_predecessor(bst* T, bst* x)
{
    if(x->l != NULL)
    {
        return bst_max(T,x->l);
    }
    else
    {
        bst* y = x->p;
        while(y != NULL)
        {
            if(y->r == x)
            {
                return y;
            }
            x = y;
            y = y->p;
        }
    }
    return NULL;
}
