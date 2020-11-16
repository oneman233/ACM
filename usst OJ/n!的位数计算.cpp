#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double wei=1.0;
    int n,i;
    scanf("%d",&n);
    if(n==0)
    {
        printf("1");
        return 0;
    }
    else
    {
        for(i=1;i<=n;i++)
            wei+=(log(i)/log(10));
        printf("%.0lf",floor(wei));//向下取整
    }
    return 0;
}
