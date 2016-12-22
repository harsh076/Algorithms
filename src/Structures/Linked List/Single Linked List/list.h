#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list* next;
}list;

int list_empty(list*);
list* list_insert(list*,int,int);
void list_print(list*);
int list_search(list*,int);
list* list_delete(list*,int);
list* list_accsess(list*,int);

int list_empty(list* head)
{
    if(head == NULL)
    return 1;
    else
    return 0;
}

list* list_insert(list* head, int data, int pos)
{
    if(pos<1)
    {
        printf("\nIncorrect Input!\n");
        return head;
    }
    else
    {
        if(list_empty(head))
        {
            list* temp = (list*)malloc(sizeof(list));
            temp->data = data;
            temp->next = NULL;
            head = temp;
        }
        else
        {
            if(pos == 1)
            {
                list* temp = (list*)malloc(sizeof(list));
                temp->data = data;
                temp->next = head;
                head = temp;
            }
            else
            {
                list* temp = (list*)malloc(sizeof(list));
                temp->data = data;
                temp->next = NULL;
                int i;
                list* temp1 = head;
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
                temp->next = temp1->next;
                temp1->next = temp;
            }
        }
    }
    return head;
}

void list_print(list* head)
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

int list_search(list* head, int val)
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

list* list_delete(list* head, int pos)
{
    if(pos == 1)
    {
        if(list_empty(head))
        {
            printf("\nIncorrect Input!");
            return head;
        }
        list* temp = head;
        head = head->next;
        free(temp);
    }
    else if(pos>1)
    {
        int i;
        list* temp = head;
        for(i=1; i<pos-1; i++)
        {
            temp = temp->next;
            if(temp->next == NULL)
            {
                printf("\nIncorrect Input!");
                return head;
            }
        }
        list* del = temp->next;
        temp->next = temp->next->next;
        free(del);
    }
    return head;
}

list* list_accsess(list* head,int pos)
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
        list* temp = head;
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
