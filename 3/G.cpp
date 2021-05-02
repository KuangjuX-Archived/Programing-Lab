#include<stdio.h>

int main()
{
    char b[1001];
    int i, count;
    while(scanf("%s", b)!=EOF)
    {
        count = 0;
        for(i = 0;;i++)
        {
            if(b[i]=='(')
                count++;
            else if(b[i]==')')
                count--;
            else if(b[i]=='B')
                break;
        }        
        printf("%d\n", count);
    }
    return 0;
}
