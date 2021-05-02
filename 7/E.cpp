#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
typedef long long lt;
  
int read()
{
    int x=0,f=1;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return x*f;
}
  
const int maxn=4000010;
int n,m,len;
int a[maxn];
int rak[maxn],sa[maxn],tp[maxn],tax[maxn];
char ss[maxn];
int height[maxn],ans;
  
void rsort()
{
    for(int i=0;i<=m;++i) tax[i]=0;
    for(int i=1;i<=n;++i) tax[rak[i]]++;
    for(int i=1;i<=m;++i) tax[i]+=tax[i-1];
    for(int i=n;i>=1;--i) sa[tax[rak[tp[i]]]--]=tp[i];
}
  
void ssort()
{
    m=1024;
    for(int i=1;i<=n;++i)
    rak[i]=a[i],tp[i]=i;
  
    rsort();
    for(int k=1;k<=n;k<<=1)
    {
        int p=0;
        for(int i=n-k+1;i<=n;++i) tp[++p]=i;
        for(int i=1;i<=n;++i) if(sa[i]>k) tp[++p]=sa[i]-k;
  
        rsort();
        memcpy(tp,rak,sizeof(rak));
        rak[sa[1]]=p=1;
        for(int i=2;i<=n;++i)
        rak[sa[i]]=(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+k]==tp[sa[i-1]+k])?p:++p;
        if(p==n)break;
        m=p;
    }
}
  
void getH()
{
    int k=0;
    for(int i=1;i<=n;++i)
    {
        if(k) --k;
        int j=sa[rak[i]-1];
        while(a[i+k]==a[j+k]) ++k;
        height[rak[i]]=k;
    }
}
  
int main()
{
    cin >> ss;
    len=strlen(ss); ss[len]='#';
    cin >> (ss+len+1);
    n=strlen(ss);
  
    for(int i=0;i<n;++i) a[i+1]=ss[i];
    ssort(); getH();
  
    for(int i=1;i<=n;++i)
    if(ans<height[i])
    if((sa[i]<=len&&sa[i-1]>len+1)||(sa[i]>len+1&&sa[i-1]<=len))
    ans=height[i];
  
    cout << ans << endl;
    return 0;
}