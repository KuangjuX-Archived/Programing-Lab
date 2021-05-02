#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node
{
    char data;
    node *lson;
    node *rson;
    node()
    {
        lson=NULL;
        rson=NULL;
    }
};
node *inser(char *s1,char *s2,int l)
{
    if(l<=0)
        return NULL;
    node *root=new node();
    root->data=*s1;
    char *p;
    for(p=s2; p!=NULL; p++)//在中序遍历结果中找到 当前根，此时在中序序列中此根左边是左子树，右边是右子树
 
    {
        if(*p==*s1)
            break;
    }
    int kk=p-s2;//左子树的长度
    root->lson=inser(s1+1,s2,kk);//访问左子树
    root->rson=inser(s1+kk+1,s2+kk+1,l-kk-1);//访问右子树
    return root;
 
}
void out(node *root)
{
    if(root==NULL)
        return ;
    out(root->lson);
    out(root->rson);
    printf("%c",root->data);
}
int main()
{
    char a[10010],b[10010];
    while(~scanf("%s%s",a,b))
    {
        int l=strlen(a);
        node *root=new node();
        root=inser(a,b,l);
        out(root);
        printf("\n");
    }
    return 0;
}