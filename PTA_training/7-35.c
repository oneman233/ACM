#include <stdio.h>
int main()
{
    int n,num,min=10000000;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&num);
        if(num<min)
            min=num;
    }
    printf("min = %d",min);
    return 0;
}
