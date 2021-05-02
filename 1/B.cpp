#include<iostream>
using namespace std;
 
bool runnian(int year)
{
    if(year%400==0)
            return 1;
        else
        {
            if(year%4==0&&year%100!=0)
            return 1;
             else
            return 0;
         }
         
}
 
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int day;
        int year;
        int month;
        int hao;
        cin>>year;
        cin>>month;
        cin>>hao;
         
        if(month>1)
        {
            day=31;
            if(month>2)
            {
                if(runnian(year))
                {
                    day=day+29;
                }
                else day=day+28;
                 
                if(month>3)
                {
                    day=day+31;
                    if(month>4)
                    {
                        day=day+30;
                        if(month>5)
                        {
                            day=day+31;
                            if(month>6)
                            {
                                day=day+30;
                                if(month>7)
                                {
                                    day=day+31;
                                    if(month>8)
                                    {
                                        day=day+31;
                                        if(month>9)
                                        {
                                            day=day+30;
                                            if(month>10)
                                            {
                                                day=day+31;
                                                if(month>11)
                                                {
                                                    day=day+30;
                                                     cout<<day+hao;
                                                }
                                                else cout<<day+hao;
                                            }
                                            else cout<<day+hao;
                                        }
                                        else cout<<day+hao;
                                    }
                                    else cout<<day+hao;
                                }
                                else cout<<day+hao;
                            }
                            else cout<<day+hao;
                     
                        }
                        else cout<<day+hao;
                    }
                    else cout<<day+hao;
                }
                else cout<<day+hao;
                 
            }
            else
            cout<<day+hao;
             
        }
        else cout<<hao;
        cout<<endl;
    }
}