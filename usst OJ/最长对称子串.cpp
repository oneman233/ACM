#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main()
{
    int x,y,len,max1=1,ans=0,i;
    char s[1000];
    gets(s);
    len=strlen(s);
    if(len%2==0)//偶数序列
    {
        for(i=0;i<len;i++)
        {
            ans=0;
            x=i;
            y=i+1;
            while(s[x]==s[y]&&x>=0&&y<len)
            {
                x--;
                y++;
                ans+=2;
            }
            if(ans>max1)
                max1=ans;
        }
    }
    else//奇数序列
    {
        for(i=1;i<len-1;i++)
        {
            ans=1;
            x=i-1;
            y=i+1;
            while(s[x]==s[y]&&x>=0&&y<len)
                {
                x--;
                y++;
                ans+=2;
            }
            if(ans>max1)
                max1=ans;
        }
    }
    printf("%d",max1);
    return 0;
}
