#include <bits/stdc++.h>
using namespace std;

long long f(long long n)
{
    for(long long i=0;i<=1000000;i++)
    {
        if(i*(i+1)/2>=n)
            return (i-1)*i/2;
    }
}

int main()
{
    int k;
    long long n;
    cin>>k;
    while(k--)
    {
        scanf("%lld",&n);
        printf("%c\n",(n-f(n)-1)%26+'a');
    }
    return 0;
}
