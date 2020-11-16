#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

int main()
{
    int n;
    cin>>n;
    double m[105];
    double dol[105],rub[105];
    memset(dol,0,sizeof(dol));
    memset(rub,0,sizeof(rub));
    _for(i,0,n)
        cin>>m[i];
    dol[0]=100.0;
    rub[0]=m[0];
    _for(i,1,n)
    {
        dol[i] = max(dol[i-1], rub[i-1]/m[i]*100);
        rub[i] = max(rub[i-1], dol[i-1]/100*m[i]);
    }
    printf("%.2lf",dol[n-1]);
    return 0;
}
