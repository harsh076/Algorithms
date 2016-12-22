#include <stdio.h>
#include <stdlib.h>

typedef struct dlist
{
    int data;
    struct dlist* prev;
    struct dlist* next;
}dlist;

int dlist_empty(dlist*);
dlist* dlist_insert(dlist*,int,int);
void dlist_print(dlist*);
int dlist_search(dlist*,int);
dlist* dlist_delete(dlist*,int);
dlist* dlist_accsess(dlist*,int);

int dlist_empty(dlist* head)
{
    if(head == NULL)
    return 1;
    else
    return 0;
}

dlist* dlist_insert(dlist* head, int data, int pos)
{
    if(pos<1)
    {
        printf("\nIncorrect Input!\n");
        return head;
    }
    else
    {
        if(dlist_empty(head))
        {
            dlist* temp = (dlist*)malloc(sizeof(dlist));
            temp->data = data;
            temp->prev = NULL;
            temp->next = NULL;
            head = temp;
        }
        else
        {
            if(pos == 1)
            {
                dlist* temp = (dlist*)malloc(sizeof(dlist));
                temp->data = data;
                temp->prev = NULL;
                temp->next = head;
                head = temp;
            }
            else
            {
                dlist* temp = (dlist*)malloc(sizeof(dlist));
                temp->data = data;
                temp->prev = NULL;
                temp->next = NULL;
                int i;
                dlist* temp1 = head;
                for(i=1; i<pos-1; i++)
                {
                    temp1 = temp1->next;
                    if(temp1 == NULL)
                    {
                        printf("\nIncorrect Input!");
                        free(temp);
                        return head;
                    }
                }
                temp->prev = temp1;
                temp->next = temp1->next;
                if(temp1->next != NULL)
                temp1->next->prev = temp;
                temp1->next = temp;
            }
        }
    }
    return head;
}

void dlist_print(dlist* head)
{
    int i=0;
    printf("\n");
    while(head != NULL)
    {
        ++i;
        printf("%d\t", head->data);
        head = head->next;
        if(i%10 == 0)
        {
            printf("\n");
        }
    }
}

int dlist_search(dlist* head, int val)
{
    int i = 1;
    while(head != NULL)
    {
        if(head->data == val)
        {
            return i;
        }
        else
        {
            head = head->next;
            ++i;
        }
    }
    return -1;
}

dlist* list_delete(dlist* head, int pos)
{
    if(pos == 1)
    {
        if(dlist_empty(head))
        {
            printf("\nIncorrect Input!");
            return head;
        }
        dlist* temp = head;
        head = head->next;
        free(temp);
    }
    else if(pos>1)
    {
        int i;
        dlist* temp = head;
        for(i=1; i<pos; i++)
        {
            temp = temp->next;
            if(temp == NULL)
            {
                printf("\nIncorrect Input!");
                return head;
            }
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    return head;
}

dlist* dlist_access(dlist* head,int pos)
{
    if(pos<1)
    {
        printf("\nIncorrect Input!");
        return NULL;
    }
    if(pos == 1)
    {
        return head;
    }
    else
    {
        dlist* temp = head;
        int i = 1;
        while (i<pos)
        {
            ++i;
            temp = temp->next;
            if(temp == NULL)
            {
                printf("\nIncorrect Input!");
                return NULL;
            }
        }
        return temp;
    }
}
