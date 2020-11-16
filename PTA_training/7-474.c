#include <stdio.h>
int squ(int a)
{
    return a*a;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        printf("%d,",squ(i));
    return 0;
}
