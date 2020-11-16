#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define sci(a) scanf("%lld",&a)
#define pri(a) printf("%d",a)
using namespace std;
typedef long long ll;
const int Max=1000000;

int n,m,ans=0;
char p[105][105];

void dfs(int i,int j)
{
    if(i<0||i>=n||j<0||j>=m)
        return;
    if(p[i][j]=='0')
        return;
    p[i][j]='0';
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
}

int main()
{
    cin>>n>>m;
    _for(i,0,n)
    {
        _for(j,0,m)
            cin>>p[i][j];
    }
    _for(i,0,n)
    {
        _for(j,0,m)
        {
            if(p[i][j]!='0')
            {
                dfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
