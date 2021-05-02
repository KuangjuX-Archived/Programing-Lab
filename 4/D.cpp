#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int v[5];
int sign[110][110][100];
struct cup//记录遍历中3个水杯容藏可乐情况
{
    int v[5];
    int step;
}temp;

void pour(int a,int b)//倒水函数，把a杯子中的可乐倒到b杯子中
{
    int sum=temp.v[a]+temp.v[b];
    if(sum>=v[b])
        temp.v[b]=v[b];
    else
        temp.v[b]=sum;
    temp.v[a]=sum-temp.v[b];
}

void bfs()
{
    int i,j;
    queue<cup>q;
    cup cnt;
    cnt.v[1]=v[1];
    cnt.v[2]=0;
    cnt.v[3]=0;
    cnt.step=0;
    q.push(cnt);
    memset(sign,0,sizeof(sign));
    sign[v[1]][0][0]=1;
    while(!q.empty())
    {
        cnt=q.front();
        q.pop();
        if(cnt.v[1]==cnt.v[3]&&cnt.v[2]==0)
        {
            printf("%d\n",cnt.step);
            return ;
        }
        for(i=1;i<4;++i)
        {
            for(j=1;j<4;++j)
            {
                if(i!=j)//自己不倒水给自己
                {
                    temp=cnt;//每个水位情况都要把所有操作枚举一遍，所以都要赋值为原始水位情况
                    pour(i,j);
                    if(!sign[temp.v[1]][temp.v[2]][temp.v[3]])
                    {
                        temp.step++;
                        q.push(temp);
                        sign[temp.v[1]][temp.v[2]][temp.v[3]]=1;
                    }
                }
            }
        }
    }
    printf("NO\n");
}

int main()
{
    while(scanf("%d%d%d",&v[1],&v[2],&v[3])&&v[1]||v[2]||v[3])
    {
        if(v[2]>v[3])
        {
            int t=v[2];
            v[2]=v[3];
            v[3]=t;
        }
        bfs();
    }
    return 0;
}