#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define sci(a) scanf("%d",&a)
#define scll(a) scanf("%lld",&a)
#define scc(a) scanf("%c",&a)
#define pb(a) push_back(a)
#define prti(a) printf("%d\n",a)
#define prtll(a) printf("%lld\n",a)
using namespace std;
typedef long long ll;
const int Max=100000;
const ll mod=998244353;

int n,m,a[Max],dp[Max];

/*
for(int i=1;i<=n;++i)
      for(int j=1;j<=m;++j)
      {
          if(j==a[i])f[i][j]=f[i-1][j]+1;
          if(j>a[i]) f[i][j]=f[i-1][j]+f[i-1][j-a[i]];
          if(j<a[i]) f[i][j]=f[i-1][j];
      }
*/

///dp[i][j]是用前i道菜花光j元的种数
///如果刚好买就买，上一道菜买到的种数多一
///如果还可以买别的，就加上剩余的钱在上一道菜那里可以买到的种数
///如果不够买就直接传递

int main()
{
    sci(n);
    sci(m);
    _for(i,0,n)
        sci(a[i]);
    memset(dp,0,sizeof(dp));
    dp[0]=1;///剩余的钱刚好够买一个菜，算一种次数
    _for(i,0,n)
    {
        for(int j=m;j>=a[i];--j)
            dp[j]+=dp[j-a[i]];
    }
    cout<<dp[m];
    return 0;
}
