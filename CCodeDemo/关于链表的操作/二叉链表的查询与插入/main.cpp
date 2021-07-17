#include <iostream>

using namespace std;

typedef struct treenode
{
    int data;
    struct treenode *left,*right;
} TreeNode,*TreePoint;
//前序遍历
void preorder(TreePoint head)
{
    if(!head)
    {
        return;
    }
    else
    {
        TreePoint p=head;
        cout<<p->data<<" ";
        preorder(p->left);
        preorder(p->right);
    }
}
//查找
TreePoint searchTree(TreePoint head,int key,TreePoint *father)
{
    TreePoint p=head;
    *father = NULL;
    while(p)
    {
        if(key<p->data)
        {
            *father = p;
            p=p->left;
        }
        else if(key>p->data)
        {
            *father = p;
            p=p->right;
        }
        else
        {
            break;
        }
    }
    return p;
}
//插入
int insertTree(TreePoint *head,int key)
{
    TreePoint s,p,father;
    s=(TreeNode *)malloc(sizeof(TreeNode));
    if(!s)
    {
        return -1;
    }
    s->data=key;
    s->left=NULL;
    s->right=NULL;
    p=searchTree(*head,key,&father);
    if(p)
    {
        return -1;
    }
    if(!father)
    {
        *head = s;
    }
    else if(key<father->data)
    {
        father->left=s;
    }
    else
    {
        father->right=s;
    }
    return 0;
}
int main()
{
    //初始化赋值，二叉查找树
    TreePoint head,data[6];
    head = (TreeNode *)malloc(sizeof(TreeNode));
    head->data = 10;
    for(int i=0; i<6; i++)
    {
        data[i] = (TreeNode *)malloc(sizeof(TreeNode));
    }
    data[0]->data=8;
    data[1]->data=12;
    data[2]->data=6;
    data[3]->data=14;
    data[4]->data=4;
    data[5]->data=16;
    //建立连接关系
    head->left = data[0];
    head->right = data[1];
    data[0]->left=data[2];
    data[0]->right=data[3];
    data[1]->left=data[4];
    data[1]->right=data[5];
    data[2]->left=NULL;
    data[2]->right=NULL;
    data[3]->left=NULL;
    data[3]->right=NULL;
    data[4]->left=NULL;
    data[4]->right=NULL;
    data[5]->left=NULL;
    data[5]->right=NULL;
    cout<<"前序遍历"<<endl;
    //前序遍历
    preorder(head);
    //查找
    cout<<endl<<"查找 key=16 及其父节点"<<endl;
    TreePoint father;
    TreePoint result=searchTree(head,16,&father);
    if(result)
    {
        cout<<result->data<<"    ";
    }
    if(father)
    {
        cout<<father->data;
    }
    //插入
    insertTree(&head,15);
    cout<<endl<<"插入15，前序遍历"<<endl;
    //前序遍历
    preorder(head);
}
