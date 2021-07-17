#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} Node,*LinkList;
int DeleteList(LinkList L,int minK,int maxK)
{
    Node *q = L,*p=L->next;
    int delTag = 0;
    while(p)
    {
        if(p->data <= minK)
        {
            q=p;
            p=p->next;
        }
        else if(p->data < maxK)
        {
            q->next = p->next;
            free(p);
            p = q->next;
            delTag = 1;
        }
        else break;
    }
    if(!delTag) return -1;
    return 0;
}
int main()
{
    Node *head,*data[10];
    head = (Node *)malloc(sizeof(Node));
    for(int i=0; i<10; i++)
    {
        data[i] = (Node *)malloc(sizeof(Node));

    }
    head->next = data[0];
    for(int i=0; i<10; i++)
    {
        data[i]->data = i;
        if(i != 9)
        {
            data[i]->next = data[i+1];
        }
        else
        {
            data[9]->next = NULL;
        }
    }
    Node *key = head;
    printf("Original: ");
    while(key)
    {
        key = key->next;
        if(key)
        {
            printf("%d ",key->data);
        }
    }
    DeleteList(head,3,8);
    key = head;
    printf("\nAfter:");
    while(key)
    {
        key = key->next;
        if(key)
        {
            printf("%d ",key->data);
        }
    }
}
