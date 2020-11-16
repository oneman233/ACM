#include <stdio.h>
#include <math.h>
int main()
{
    float x,y,length;
    scanf("%f %f",&x,&y);
    length=sqrt(x*x+y*y);
    if(length<10.0)
        printf("1");
    else
        printf("0");
    return 0;
}
