#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double a[110],mei[110],lu[110];
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    mei[1]=100.0;
    lu[1]=mei[1]/100.0*a[1];
    for(int i=2;i<=n;++i)
    {
        mei[i]=max(mei[i-1],lu[i-1]/a[i]*100.0);
        lu[i]=max(lu[i-1],mei[i-1]/100.0*a[i]);
    }
    printf("%.2lf",mei[n]);
    return 0;
}
