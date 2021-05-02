#include<iostream>
using namespace std;
int main()
{
    int dp[205]={0};
    int n,a,b;
    int k[205];
    int i;
    bool flag=true;
  
    cin>>n>>a>>b;
    for(i=1;i<=n;i++)
        cin>>k[i];
         
    dp[a]=1;//将a层电梯初值设为1
    while(flag)//至少循环一次
    {
        flag=false;
        for(i=1;i<=n;i++)
        {
            if(dp[i]>0)//保证每次从a层开始
            {
                if(i-k[i]>0)//保证能下降
                {
                    if(dp[i-k[i]]==0||dp[i-k[i]]>dp[i]+1)
                    {
                        dp[i-k[i]]=dp[i]+1;//下降后次数=下降前次数+1
                        flag=true;//满足条件继续循环
                    }
                }
                if(i+k[i]<=n)//保证不会超出最大楼层
                {
                    if(dp[i+k[i]]==0||dp[i+k[i]]>dp[i]+1)
                    {                       
                        dp[i+k[i]]=dp[i]+1;//上升后次数=上升前次数+1
                        flag=true;//满足条件继续循环
                    }
                }
            }
        }
    }
    cout<<dp[b]-1<<endl;
  
    return 0;
}