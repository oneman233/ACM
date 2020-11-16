#include <stdio.h>
int main()
{
    int n,sum=0,count=0;
    scanf("%d",&n);
    do
    {
        sum+=n%10;
        n/=10;
        count++;
    }
    while(n!=0);
    printf("%d %d",count,sum);
    return 0;
}
