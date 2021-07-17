#include <iostream>

using namespace std;

typedef struct treenode
{
    char data;
    struct treenode *left,*right;
} TreeNode,*TreePoint;
//ǰ�����
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
//�������
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
//�������
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
    //��ʼ����ֵ
    TreePoint head,data[6];
    head = (TreeNode *)malloc(sizeof(TreeNode));
    head->data = 'A';
    for(int i=0; i<6; i++)
    {
        data[i] = (TreeNode *)malloc(sizeof(TreeNode));
        data[i]->data = 'B'+i;
    }
    //�������ӹ�ϵ
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
    cout<<"ǰ�����"<<endl;
    //ǰ�����
    preorder(head);
    cout<<endl<<"�������"<<endl;
    //�������
    inorder(head);
    cout<<endl<<"�������"<<endl;
    //�������
    postorder(head);
}
