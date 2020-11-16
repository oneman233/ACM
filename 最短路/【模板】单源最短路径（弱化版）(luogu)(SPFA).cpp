#include <bits/stdc++.h>
using namespace std;
const int maxn=500000;
typedef unsigned long long ll;
const ll INF=2147483647;

int n,m,s;
ll dis[maxn+5];
int from[maxn+5],to[maxn+5];
ll val[maxn+5];

void BF()
{
    for(int i=1;i<=n;++i)
        dis[i]=INF;
    dis[s]=0;
    int tmp=n-1;
    while(tmp--)///每一次起码更新一个点
    {
        for(int i=1;i<=m;++i)
            dis[to[i]]=min(dis[to[i]],dis[from[i]]+val[i]);
    }
}

int main()
{
    cin>>n>>m>>s;
    for(int i=1;i<=m;++i)
        cin>>from[i]>>to[i]>>val[i];
    for(int i=1;i<=m;++i)
        if(from[i]==to[i])
            val[i]=0;
    BF();
    for(int i=1;i<=n;++i)
        cout<<dis[i]<<" ";
    return 0;
}
