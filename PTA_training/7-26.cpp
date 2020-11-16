#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,j,read,count=0,flag=0;
    int gui[100000],min[100000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        min[i]=100001;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&read);
        if(read==i)
            flag++;
    }
    if(flag==n)
    {
        printf("%d",flag);
        return 0;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&read);
        for(j=0;j<n;j++)
        {
            if(read<min[j])
            {
                min[j]=read;
                gui[j]=1;
                break;
            }
            else;
        }
    }
    for(i=0;i<n;i++)
    {
        if(gui[i]==1)
            count++;
    }
    printf("%d",count);
    return 0;
}
