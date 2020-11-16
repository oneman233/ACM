#include <bits/stdc++.h>
using namespace std;

int n;
long long ans=0;
struct man
{
    long long a,b;
}m[100010];

int main()
{
    cin>>n;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;++i)
        cin>>m[i].a>>m[i].b;

    return 0;
}
