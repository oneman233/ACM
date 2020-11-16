#include <stdio.h>
#include <math.h>
int jie(int k)
{
    int i,result=1;
    do
    result*=k;
    while(--k);
}
int main()
{
    /*int i=1;
    float x,sum=1.0;
    scanf("%f",&x);
    while(1)
    {
        sum+=pow(x,i)/jie(i);
        if(pow(x,i)/jie(i)<0.00001)
            break;
        i++;
    }
    printf("%.4f",sum);*/
    double x;
    scanf("%lf",&x);
    printf("%.4lf",exp(x));
}
