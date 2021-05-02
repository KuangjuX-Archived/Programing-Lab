#include<iostream>
 
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int n,p;
        cin>>n;
        cin>>p;
        int shuzu[1001];
        for(int i=1;i<=n;i++)
        {
            cin>>shuzu[i];
        }
         
        int flag=0;
        for(int i=1;i<n+1;i++)
        {
            int sum=0;
            for(int j=i;j<n+1;j++)
            {
                sum+=shuzu[j];
                 
                if(sum==p)
                {
                    flag++;
                }
                 
            }
        }
        cout<<flag<<endl;
         
         
    }
}