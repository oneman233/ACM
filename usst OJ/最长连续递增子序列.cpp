#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num[110000];
    int n,i;
    int wei,maxlen=0,len=0;
    memset(num,0,sizeof(num));
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);
    for(i=0;i<n;i++)
    {

        if(num[i+1]>num[i])
        {
            len++;
            if(len>maxlen)
            {
                maxlen=len;
                wei=i+1;
            }
        }
        else
            len=0;
    }
    if(maxlen==0)
    {
        printf("%d",num[0]);
        return 0;
    }
    else
    {
        for(i=wei-maxlen;i<=wei;i++)
        {
        printf("%d",num[i]);
        if(i!=wei)
            printf(" ");
        }
        return 0;
    }
}
