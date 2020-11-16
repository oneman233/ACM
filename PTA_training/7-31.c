#include <stdio.h>
int year(int a)
{
    if(a%4==0&&a%100!=0&&a%400!=0)
        return 1;//1´ú±íÈòÄê
    else
        return 0;
}
int main()
{
    int n,i,count=0;
    scanf("%d",&n);
    if(n<=2000||n>2100)
    {
        printf("Invalid year!");
        return 0;
    }
    for(i=2000;i<=n;i++)
    {
        if(year(i)==1)
        {
            printf("%d\n",i);
            count++;
        }
        else
            ;
    }
    if(count==0)
    {
        printf("None");
        return 0;
    }
    return 0;
}
