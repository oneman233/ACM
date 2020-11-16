#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int a,b;
int vis[105];

signed main()
{
    memset(vis,0,sizeof(vis));
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        cin>>a>>b;
        for(int j=a;j<=b;++j)
            vis[j]++;
    }
    for(int i=1;i<=n;++i){
        if(vis[i]!=1){
            cout<<i<<' '<<vis[i];
            return 0;
        }
    }
    cout<<"OK";
    return 0;
}
