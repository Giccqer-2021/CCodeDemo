#include <iostream>
#define LEN 10

using namespace std;

/*����*/
typedef struct node
{
    int data;
    struct node *next;
} NODE,*LinkList;

/*����*/
LinkList Find_list(LinkList L,int k)
{
    LinkList p;
    int i=1;
    p=L->next;
    while(p && i <k)
    {
        p=p->next;
        i++;
    }
    if(p&&i == k)
    {
        return p;
    }
    return NULL;
}
/*����*/
int Insert_List(LinkList L,int k,int elem)
{
    LinkList p,s;
    if(k==1)
    {
        p=L;
    }
    else
    {
        p=Find_list(L,k-1);
    }
    if(!p)
    {
        return -1;
    }
    s=(NODE *)malloc(sizeof(NODE));
    if(!s)
    {
        return -1;
    }
    s->data = elem;
    s->next = p->next;
    p->next = s;
    return 0;
}
/*ɾ��*/
int Delete_List(LinkList L,int k)
{
    LinkList p,s;
    if(k==1)
    {
        p=L;
    }
    else
    {
        p=Find_list(L,k-1);
    }
    if(!p||!p->next)
    {
        return -1;
    }
    s=p->next;
    p->next=s->next;
    free(s);
    return 0;
}
int main()
{
    //��ʼ��
    LinkList head,data[LEN];
    head = (NODE *)malloc(sizeof(NODE));
    for(int i=0; i<LEN; i++)
    {
        data[i] = (NODE *)malloc(sizeof(NODE));
    }
    //��ֵ
    head->next = data[0];
    for(int i=0; i<LEN-1; i++)
    {
        data[i]->next = data[i+1];
        data[i]->data = i*10;
    }
    data[LEN-1]->next=NULL;
    data[LEN-1]->data=(LEN-1)*10;
    //����
    LinkList p = head;
    cout<<"����"<<endl;
    while(p=p->next)
    {
        cout<<p->data<<" ";
    }
    //����
    cout<<endl<<"����"<<endl;
    cout<<Find_list(head,6)->data<<" ";
    //����
    Insert_List(head,7,11);
    p = head;
    cout<<endl<<"��������"<<endl;
    while(p=p->next)
    {
        cout<<p->data<<" ";
    }
    //ɾ��
    Delete_List(head,9);
    p = head;
    cout<<endl<<"ɾ�������"<<endl;
    while(p=p->next)
    {
        cout<<p->data<<" ";
    }
}
