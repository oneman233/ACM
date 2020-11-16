#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

double qpow(double p,int n)
{
    double ans=1.0;
    while(n){
        if(n&1)
            ans*=p;
        p*=p;
        n>>=1;
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        ull a,b;
        scanf("%llu %llu",&a,&b);
        ull c=a+b/1000*11;
        b%=1000;
        c+=b/100;
        double ans=c*0.012/23.0;
        printf("%.3lf",ans);
        if(t!=0)
            printf("\n");
    }
    return 0;
}
/*
1000
10000000000000000000 10000000000000000000
*/
