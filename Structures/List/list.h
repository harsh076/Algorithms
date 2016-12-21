#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

int empty(node*);
node* insert(node*,int,int);
void print(node*);
int search(node*,int);
node* delete(node*,int);
node* accsess(node*,int);

int empty(node* head)
{
    if(head == NULL)
    return 1;
    else
    return 0;
}

node* insert(node* head, int data, int pos)
{
    if(empty(head))
    {
        node* temp = (node*)malloc(sizeof(node));
        temp->data = data;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        if(pos == 1)
        {
            node* temp = (node*)malloc(sizeof(node));
            temp->data = data;
            temp->next = head;
            head = temp;
        }
        else
        {
            node* temp = (node*)malloc(sizeof(node));
            temp->data = data;
            temp->next = NULL;
            int i;
            node* temp1 = head;
            for(i=1; i<pos-1; i++)
            {
                temp1 = temp1->next;
                if(temp1 == NULL)
                {
                    printf("\nIncorrect Input!");
                    return head;
                }
            }
            temp->next = temp1->next;
            temp1->next = temp;
        }
    }
    return head;
}

void print(node* head)
{
    int i=0;
    printf("\n");
    while(head != NULL)
    {
        ++i;
        printf("%3d -> ", head->data);
        head = head->next;
        if(i%20 == 0)
        {
            printf("\n");
        }
    }
    printf("NULL");
}

int search(node* head, int val)
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

node* delete(node* head, int pos)
{
    if(pos == 1)
    {
        head = head->next;
    }
    else if(pos>1)
    {
        int i;
        node* temp = head;
        for(i=2; (i<pos) && (temp->next != NULL); i++)
        {
            temp = temp->next;
        }
        if(temp->next == NULL)
        {
            printf("\n\nIncorrect Input!\n");
            return head;
        }
        node* temp1 = NULL;
        temp1 = temp->next;
        temp->next = temp1->next;
    }
    return head;
}

node* accsess(node* head,int pos)
{
    if(pos == 1)
    {
        return head;
    }
    else if(pos > 1)
    {
        node* temp = head;
        int i = 1;
        while (i<pos)
        {
            ++i;
            temp = temp->next;
        }
        return temp;
    }
    else
    {
        return NULL;
    }
}
