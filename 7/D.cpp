#include <iostream>
#include <set>
using namespace std;
 
int main() {
    int T;
    int N,NC;
    string s;
    cin>>T;
    while(T--)
    {
        cin>>N>>NC;
        cin>>s;
        set<string> sub_str;
        for(int i = 0; i <= s.size() - N; i++)
        {
            sub_str.insert(s.substr(i,N));
        }
        cout<<sub_str.size()<<endl;
        if(T!=0)
        cout<<endl;
    }
    return 0;
}