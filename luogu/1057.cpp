#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int n,m;
ull ans[35][35];

int l(int x)
{
    if(x>1)
        return x-1;
    else
        return n;
}

int r(int x)
{
    if(x<n)
        return x+1;
    else
        return 1;
}

void dfs(int i,int j)
{
    if(j>m)
        return;
    ans[l(i)][j+1]+=ans[i][j];
    dfs(l(i),j+1);
    ans[r(i)][j+1]+=ans[i][j];
    dfs(r(i),j+1);
}

int main()
{
    cin>>n>>m;
    ans[n][0]=1;
    ///dfs(n,0);
    for(int j=1;j<=m;++j)
        for(int i=1;i<=n;++i)
            ans[i][j]=ans[l(i)][j-1]+ans[r(i)][j-1];
    cout<<ans[n][m];
    return 0;
}
