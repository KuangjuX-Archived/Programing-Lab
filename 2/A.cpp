#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int N;
        cin>>N;
        int a[7];
        for (int i=6;i>=0;i--)
        {
            cin>>a[i];
             
        }
        int i=0;
        int b[7]={100,50,20,10,5,2,1};
        int fee=0;
        int cnt=0;
        while(fee<N&&i<7)
        {
             
            while(fee+b[i]<=N&&a[i]>0)
            {
                fee+=b[i];
                a[i]--;
                cnt++;
                 
            }
            if(fee==N) break;
            else i++;
        }
        if (fee!=N)
            cout<<-1<<endl;
        else
        cout<<cnt<<endl;
             
    }
 
 }