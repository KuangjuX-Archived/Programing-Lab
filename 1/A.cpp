#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int year;
        cin>>year;
        int a=0;
//相当于判断函数
        if(year%400==0)//四百年的
            a=1;
        else
        {
            if(year%4==0&&year%100!=0)//四年周期但不是百年的
            a=1;
             else
            a=0;
         }

        if(a==1)
        {
            cout<<"Yes"<<endl;
        }
         else
        {
            cout<<"No"<<endl;
        }
    }
 }