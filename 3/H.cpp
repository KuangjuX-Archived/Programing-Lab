#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef vector<string> strArray;
int main()
{
	strArray forwardStack,backStack;
	string currentUrl="http://www.acm.org/";
	string action, url;
	cin>>action;
	while(action!="QUIT")
	{
 
			if(action=="VISIT")
				{
					cin>>url;
					backStack.push_back(currentUrl);
					cout<<url<<endl; 
					currentUrl=url;
					forwardStack.clear();
				}
			if(action=="BACK") 
				{
					if(!backStack.empty())
					{
						forwardStack.push_back(currentUrl);
						currentUrl=backStack.back();
						cout<<currentUrl<<endl;
						backStack.pop_back();
					}
					else
					    cout<<"Ignored"<<endl;;
				}
			if(action=="FORWARD")
				{
					if(!forwardStack.empty())
					{
						backStack.push_back(currentUrl);
						currentUrl=forwardStack.back();
						cout<<currentUrl<<endl;
						forwardStack.pop_back();
					}
					else
					    cout<<"Ignored"<<endl;
				}
		cin>>action;
	}
	return 0;
}