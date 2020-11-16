#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<b;++i)
using namespace std;
typedef long long ll;
const int maxn=100000;

int l,w,a,n;
int x,y;
int pool[5005][5005],sum[5005][5005];

int main()
{
    memset(pool,0,sizeof(pool));
    memset(sum,0,sizeof(sum));
    cin>>l>>w>>a>>n;
    _for(i,0,n)
    {
        scanf("%d %d",&x,&y);
        pool[x][y]++;
    }
  	sum[0][0]=pool[0][0];
  	for(int i=1;i<=l;++i)
        sum[0][i]=sum[0][i-1]+pool[0][i];
    for(int i=1;i<=l;++i)
        sum[i][0]=sum[i-1][0]+pool[i][0];
    for(int i=1;i<=l;++i)
    {
        for(int j=1;j<=w;++j)
        {
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+pool[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<=l-a;++i)
    {
        for(int j=0;j<=w-a;++j)
        {
            ans=max(ans,sum[i+a][j+a]-sum[i+a][j]-sum[i][j+a]+sum[i][j]);
        }
    }
    cout<<ans;
    return 0;
}
