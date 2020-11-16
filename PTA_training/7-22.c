#include <stdio.h>
#include <math.h>
int shu(int a)
{
    int i;
    if(a==1||a<=0)
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
    int count=0,i,n,k,sum=0;
    scanf("%d %d",&n,&k);
    for(i=n;count<k;i--)
    {
        if(shu(i)==0)
        {
            printf("%d",i);
            count++;
            sum+=i;
            if(i==2||count==k)
            {
                printf("=%d",sum);
                return 0;
            }
            else
                printf("+");
        }
    }
}
