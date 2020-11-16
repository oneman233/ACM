#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int e,f;
    e=(c-a)*60+(d-b);
    f=e/60;
    e%=60;
    cout<<f<<" "<<e;
    return 0;
}
