#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int nm;
    cin>>nm;
    for(int i=0;i<nm;i++)
    {
        string a;
        cin>>a;
        int length = a.length();
        int m=0,n=0;
        for(int j=0;j<length;j++)
        {
            if(a[j]=='W') n++;
            if(a[j]=='S') n--;
            if(a[j]=='A') m--;
            if(a[j]=='D') m++;
        }
        cout<<m<<" "<<n<<endl;
         
    }
}