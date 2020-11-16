#include <stdio.h>
#include <math.h>
int shu(int a)
{
    int i;
    if(a==1)
        return 1;
    for(i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
            return 1;
    }
    return 0;//返回零则是质数
}
int main()
{
    int m,n,i,count=0,sum=0;
    scanf("%d %d",&m,&n);
    for(i=m;i<=n;i++)
    {
        if(i==1)
            continue;
        if(shu(i)==0)
        {
            count++;
            sum+=i;
        }
    }
    printf("%d %d",count,sum);
    return 0;
}
//1不是质数
