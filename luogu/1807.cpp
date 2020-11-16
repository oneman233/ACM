#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1000;
const ll inf=0x3f3f3f3f;

int n,m;
ll x,y,v;
ll p[maxn+5][maxn+5];

void spfa()
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    memset(p,0x3f,sizeof(p));
    cin>>n>>m;
    while(m--){
        cin>>x>>y>>v;
        p[x][y]=v;
    }
    return 0;
}
