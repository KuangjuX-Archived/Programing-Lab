#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define OK 1
#define ERROR 0

typedef char ElemType;
typedef double ElemType2;
typedef bool Status;

typedef struct SNode
{
    ElemType data;
    struct SNode *next;
}SNode,*SLNode;

typedef struct
{
    SLNode top;
    int count;
}SLinkStack;

//Status Init_LStack(SLinkStack *s);//初始化栈
//Status GetTop_LStack(SLinkStack s,ElemType *e);//获取栈顶元素
//Status Push(SLinkStack *s,ElemType e);//在栈顶插入元素
//Status Pop(SLinkStack *s,ElemType *e);//栈顶元素出栈
//Status Out_LStack(SLinkStack s);//输出栈中元素

Status Init_LStack(SLinkStack *s)
{
    s->top=(SLNode)malloc(sizeof(SNode));
    if(!s)
        return ERROR;
    s->top=NULL;
    s->count=0;
    return OK;
}
Status Push(SLinkStack *s,ElemType e)
{
    SLNode p;
    p=(SLNode)malloc(sizeof(SNode));
    if(!p)
       return ERROR;
    p->data=e;
    p->next=s->top;
    s->top=p;
    s->count++;
    return OK;
}
Status Pop(SLinkStack *s,ElemType *e)
{
    SLNode p;
    if(s->top==NULL)
        return ERROR;
    *e=s->top->data;
    p=s->top;
    s->top=p->next;
    free(p);
    s->count--;
    return OK;
}
Status GetTop_LStack(SLinkStack s,ElemType *e)
{
    if(s.top==NULL)
        return ERROR;
    *e=s.top->data;
    return OK;
}
Status Out_LStack(SLinkStack s)
{
    SLNode p;
    p=s.top;
    printf("栈内容为: ");
    while(p)
    {
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}


typedef struct SNode2
{
    ElemType2 data;
    struct SNode2 *next;
}SNode2,*SLNode2;

typedef struct
{
    SLNode2 top;
    int count;
}SLinkStack2;

//Status Init_LStack2(SLinkStack2 *s);//初始化栈
//Status GetTop_LStack2(SLinkStack2 s,ElemType2 *e);//获取栈顶元素
//Status Push2(SLinkStack2 *s,ElemType2 e);//在栈顶插入元素
//Status Pop2(SLinkStack2 *s,ElemType2 *e);//栈顶元素出栈
//Status Out_LStack2(SLinkStack2 s);//输出栈中元素

Status Init_LStack2(SLinkStack2 *s)
{
    s->top=(SLNode2)malloc(sizeof(SNode2));
    if(!s)
        return ERROR;
    s->top=NULL;
    s->count=0;
    return OK;
}
Status Push2(SLinkStack2 *s,ElemType2 e)
{
    SLNode2 p;
    p=(SLNode2)malloc(sizeof(SNode2));
    if(!p)
       return ERROR;
    p->data=e;
    p->next=s->top;
    s->top=p;
    s->count++;
    return OK;
}
Status Pop2(SLinkStack2 *s,ElemType2 *e)
{
    SLNode2 p;
    if(s->top==NULL)
        return ERROR;
    *e=s->top->data;
    p=s->top;
    s->top=p->next;
    free(p);
    s->count--;
    return OK;
}
Status GetTop_LStack2(SLinkStack2 s,ElemType2 *e)
{
    if(s.top==NULL)
        return ERROR;
    *e=s.top->data;
    return OK;
}
Status Out_LStack2(SLinkStack2 s)
{
    SLNode2 p;
    p=s.top;
    printf("栈内容为: ");
    while(p)
    {
        printf("%f ",p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}

int main()
{
    int T;string s;double e,e2;char m;
    cin>>T;
    SLinkStack2 S1;SLinkStack S2;
    while(T--)
    {
        Init_LStack2(&S1);Init_LStack(&S2);
        cin>>s;
        for(unsigned int i=0;i<s.length();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                Push2(&S1,s[i]-'0');
            }
            else
            {
                if(s[i]=='+'||s[i]=='-')
                    Push(&S2,s[i]);
                else
                {
                    Pop2(&S1,&e);
                    if(s[i]=='*')
                        e*=(s[i+1]-'0');
                    else
                        e/=(s[i+1]-'0');
                    i++;
                    Push2(&S1,e);
                }
            }

        }
        while(S1.top!=NULL&&S2.top!=NULL)
        {
            Pop2(&S1,&e2);Pop(&S2,&m);Pop2(&S1,&e);
            if(m=='+')
                e+=e2;
            else
                e-=e2;
            Push2(&S1,e);
        }
        GetTop_LStack2(S1,&e);
        cout<<e<<endl;
    }
}

