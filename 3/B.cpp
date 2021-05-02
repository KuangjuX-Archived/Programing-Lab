#include <iostream>
#define MAXSIZE 5001
using namespace std;

typedef struct queue
{
    int data[MAXSIZE];
    int front;
    int rear;
    int capacity;
}Queue;
void InitQueue(Queue *q)
{
    q->front=0;
    q->rear=0;
    q->capacity=0;
}
void EnterQueue(Queue *q,int &data)
{
    if(MAXSIZE!=q->rear)
    {
        q->data[++q->rear]=data;
        q->capacity++;
    }
}
int OuterQueue(Queue *q)
{
    int data;
    if(q->front!=q->rear)
    {
        data=q->data[++q->front];
        q->capacity--;
    }
    return data;
}
int main()
{
    int N,m,data,m1,m2;
    Queue q1,q2;
    cin>>N;
    while(N--)
    {
        InitQueue(&q1);
        InitQueue(&q2);
        bool isq1=true;
        cin>>m;
        for(int i=1;i<=m;i++)
            EnterQueue(&q1,i);
        while(q1.capacity>3||q2.capacity>3)
        {
            if(isq1)
            {
                m1=q1.capacity;
                for(int i=1;i<=m1;i++)
                {
                    if(i%2!=0)
                    {
                        data=OuterQueue(&q1);
                        EnterQueue(&q2,data);
                    }
                    else
                        OuterQueue(&q1);
                }
                isq1=false;
                InitQueue(&q1);
            }
            else
            {
                m2=q2.capacity;
                for(int i=1;i<=m2;i++)
                {
                    if(i%3!=0)
                    {
                        data=OuterQueue(&q2);
                        EnterQueue(&q1,data);
                    }
                    else
                        OuterQueue(&q2);
                }
                isq1=true;
                InitQueue(&q2);
            }
        }
        if(isq1)
        {
            cout<<q1.data[1];
            for(int i=2;i<=q1.capacity;i++)
                cout<<" "<<q1.data[i];
            cout<<endl;
        }
        else
        {
            cout<<q2.data[1];
            for(int i=2;i<=q2.capacity;i++)
                cout<<" "<<q2.data[i];
            cout<<endl;
        }
    }
    return 0;
}
