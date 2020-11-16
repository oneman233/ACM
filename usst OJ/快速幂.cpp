#include <iostream>

using namespace std;

unsigned long long int quickpow(unsigned long long int a,unsigned long long int b)
{
    unsigned long long int r=1,base=a;
    while(b!=0)
    {
        if(b%2)
            r*=base;
        base*=base;
        b/=2;
    }
    return r;
}

int main()
{
    unsigned long long int a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld",quickpow(a,b));
    return 0;
}
