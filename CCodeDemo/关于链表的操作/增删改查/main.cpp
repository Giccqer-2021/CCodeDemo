#include <iostream>
#define LEN 10

using namespace std;

/*链表*/
typedef struct node
{
    int data;
    struct node *next;
} NODE,*LinkList;

/*查找*/
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
/*插入*/
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
/*删除*/
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
    //初始化
    LinkList head,data[LEN];
    head = (NODE *)malloc(sizeof(NODE));
    for(int i=0; i<LEN; i++)
    {
        data[i] = (NODE *)malloc(sizeof(NODE));
    }
    //赋值
    head->next = data[0];
    for(int i=0; i<LEN-1; i++)
    {
        data[i]->next = data[i+1];
        data[i]->data = i*10;
    }
    data[LEN-1]->next=NULL;
    data[LEN-1]->data=(LEN-1)*10;
    //遍历
    LinkList p = head;
    cout<<"遍历"<<endl;
    while(p=p->next)
    {
        cout<<p->data<<" ";
    }
    //查找
    cout<<endl<<"查找"<<endl;
    cout<<Find_list(head,6)->data<<" ";
    //插入
    Insert_List(head,7,11);
    p = head;
    cout<<endl<<"插入后遍历"<<endl;
    while(p=p->next)
    {
        cout<<p->data<<" ";
    }
    //删除
    Delete_List(head,9);
    p = head;
    cout<<endl<<"删除后遍历"<<endl;
    while(p=p->next)
    {
        cout<<p->data<<" ";
    }
}
