#include <stdio.h>
int sum()
{
    int i,result=0;
    for(i=1;i<=99;i++)
        result+=i*(i+1);
    return result;
}
int main()
{
    printf("%d",sum());
    return 0;
}
