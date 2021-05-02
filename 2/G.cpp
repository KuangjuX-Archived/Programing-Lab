#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[1000]={0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int t=0;
     
    bool temp[1000] = {false};
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = i+1; j < n; j++ )
        {
            for ( int k = j+1; k < n; k++ )
            {
                if (a[i]+a[j] == a[k])
                    temp[k] = true;
            }
        }
    }
    for ( int i = 0; i < n; i++ )
    {
        if ( temp[i] ) t++; 
    }
    cout<<t<<endl;
 
}  