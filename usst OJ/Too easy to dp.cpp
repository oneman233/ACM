#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
    int n,m,k;
    long in[25];
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<k;i++)
    {
        scanf("%ld",&in[i]);
    }
    printf("%ld\n",n*m-1);
    if(k==1)
    {
        printf("%ld",in[0]);
    }
    else
    {
        long ans=n*m+1;
        /*二进制枚举*/
        for(int i=1;i<(1<<k);i++)
        {
            long temp=0;
            for(int j=0;j<k;j++)
            {
                if(i&(1<<j))
                {
                    temp+=in[j];
                }
            }
            if(abs((n*m-temp)-temp)<ans)
                ans=abs((n*m-temp)-temp);
        }
        printf("%ld",ans);
    }
    return 0;
}
