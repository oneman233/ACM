#include <stdio.h>
int main()
{
    int flag=1,i=1;
    float pi=0.0;
    while(1)
    {
        if(flag==1)
        {
            pi+=1.0/i;
            flag=0;
            i+=2;
        }
        else
        {
            pi-=1.0/i;
            flag=1;
            i+=2;
        }
        if(1.0/i<1e-6)
        {
             if(flag==1)
        {
            pi+=1.0/i;
            break;
        }
        else
        {
            pi-=1.0/i;
            break;
        }
        }
    }
    printf("%.6f",4*pi);
    return 0;
}
