#include<iostream>
 
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        int a[10]={0};
        for(int j=1;j<=m;j++)
        {
            for(int k=j;k>0;k/=10)
            {
                int c=k%10;
                a[c]++;
            }
        }
        cout<<a[0];
        for(int j=1;j<10;j++)
        {
            cout<<" "<<a[j];
             
     
         
    }
        cout<<endl;
}
}