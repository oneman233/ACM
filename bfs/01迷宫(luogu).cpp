#include <bits/stdc++.h>
using namespace std;
const maxn=1000;

int n,m;
int a[maxn+5][maxn+5];
int ans[maxn+5][maxn+5];

bool ok(int i,int j)
{
    if(i<1||i>n||j<1||j>n)
        return false;
}

void bfs(int i,int j)
{

}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            ans[i][j]=1;
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {

        }
    }
    return 0;
}
