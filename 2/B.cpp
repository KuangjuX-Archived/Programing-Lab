#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--){
     
    int N;
    cin>>N;
    int a[]={0,1,4,7,6,5,6,3,6,9,0,1,6,3,6,5,6,7,4,9};
    int c=N%20;
    cout<<a[c]<<endl;
}
} 