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
    int n,num[1000],cha,i,j=0;
    scanf("%d",&n);
    for(i=2;j<1000;i++,j++)
    {
        if(shu(i)==0)
        {
            num[j]=i;
            j++;
        }
    }
    for(j=0;j<1000;j++)//充分说明答案在前一千个质数里
    {
        cha=n-num[j];
        if(shu(cha)==0)
        {
            printf("%d = %d + %d",n,num[j],cha);
            return 0;
        }
    }
}
