#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    int n;
    bool noduichen=false;
    scanf("%c %d",&c,&n);
    char s[105][105];
    char temp[105][105];
    for(int i=0;i<n;i++)
    {
        getchar();
        for(int j=0;j<n;j++)
        {
            scanf("%c",&s[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp[n-i-1][n-j-1]=s[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(temp[i][j]!=s[i][j])
            {
                noduichen=true;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(s[i][j]=='@')
                s[i][j]=c;
        }
    }
    if(!noduichen)
        printf("bu yong dao le\n");
    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            printf("%c",s[i][j]);
        }
        printf("\n");
    }
    return 0;
}
