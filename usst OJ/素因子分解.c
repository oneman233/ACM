#include <stdio.h>
#include <math.h>
int zhishu(int a)
{
    int i;
    if(a==1)
        return 0;
    for(i=2;i<sqrt(a);i++)
    {
        if(a%i==0)
        return 0;
    }
    return 1;
}
int main()
{
    int shu[1001],count[1001],i=2,j=0,geshu=0;
    long int n,cun;
    scanf("%ld",&n);
    if(n==1)
    {
        printf("1=1");
        return 0;
    }
    cun=n;
    for(i=0;i<1001;i++)
        count[i]=0;
    i=2;
    while(j<1001)
    {
        if(zhishu(i)==1)
        {
            shu[j]=i;
            j++;
            i++;
        }
        else
            i++;
    }//存了前1000个质数
    for(i=0;i<1001;i++)
    {
        while(n%shu[i]==0)
        {
            geshu++;
            count[i]++;
            n/=shu[i];
            if(n==1)
             break;
        }
    }
    printf("%ld=",cun);
    for(i=0;i<1001;i++)
    {
        if(count[i]!=0)
        {
            if(count[i]==1)
            {
                printf("%d",shu[i]);
                geshu--;
                if(geshu!=0)
                    printf("*");
            }
            else
            {
                printf("%d^%d",shu[i],count[i]);
                geshu-=count[i];
                if(geshu!=0)
                    printf("*");
            }
        }
        else;
    }
    return 0;
}
