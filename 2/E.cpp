#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int sheng[100001];
    int zong[100001];
    int shengm=0;
    for(int i=0;i<n;i++)
    {
        cin>>sheng[i];
        shengm+=sheng[i];
    }
    int max1,max2;
    cin>>max1;
    cin>>max2;
    if(max2>max1)
    {
        int t=max1;
        max1=max2;
        max2=t;
    }
    for(int i=2;i<n;i++)
    {
        cin>>zong[i];
        if(zong[i]>max2)
        {
            max2=zong[i];
            if(max2>max1)
            {
                int t=max1;
                max1=max2;
                max2=t;
            }
        }
         
    }
    if(shengm>max1+max2)
    {
        cout<<"NO"<<endl; 
    }
    else cout<<"YES"<<endl;
 
     
 
}