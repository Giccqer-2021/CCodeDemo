#include <iostream>

using namespace std;

typedef struct treenode
{
    char data;
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
//中序遍历
void inorder(TreePoint head)
{
    if(!head)
    {
        return;
    }
    else
    {
        TreePoint p=head;
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
}
//后序遍历
void postorder(TreePoint head)
{
    if(!head)
    {
        return;
    }
    else
    {
        TreePoint p=head;
        postorder(p->left);
        postorder(p->right);
        cout<<p->data<<" ";
    }
}
//main
int main()
{
    //初始化赋值
    TreePoint head,data[6];
    head = (TreeNode *)malloc(sizeof(TreeNode));
    head->data = 'A';
    for(int i=0; i<6; i++)
    {
        data[i] = (TreeNode *)malloc(sizeof(TreeNode));
        data[i]->data = 'B'+i;
    }
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
    cout<<endl<<"中序遍历"<<endl;
    //中序遍历
    inorder(head);
    cout<<endl<<"后序遍历"<<endl;
    //后序遍历
    postorder(head);
}
