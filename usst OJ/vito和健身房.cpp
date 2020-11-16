#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define scii(a,b) scanf("%d%d",&a,&b)
#define sci(a) scanf("%d",&a)
#define scll(a,b) scanf("%lld%lld",&a,&b)
#define scl(a) scanf("%lld",&a)
#define pri(a) printf("%d",a)
#define prl(a) printf("%lld",a)
#define prn() printf("\n")
#define pu(a) push_back(a)
#define po() pop_back()
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
using namespace std;
const int maxn=300000;
const int inf=1e9;
typedef long long ll;

int n,vtmp,ltmp,rtmp;
int dis[101][101],v[101];
int ans=inf;

int main()
{
    sci(n);
    re(i,1,n)
    {
        re(j,1,n)
        {
            dis[i][j]=inf;
        }
    }
    re(i,1,n)
        dis[i][i]=0;
    re(i,1,n)
    {
        sci(vtmp);
        scii(ltmp,rtmp);
        dis[i][ltmp]=dis[ltmp][i]=1;
        dis[i][rtmp]=dis[rtmp][i]=1;
        v[i]=vtmp;
    }
    re(k,1,n)
    {
        re(i,1,n)
        {
            re(j,1,n)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    re(i,1,n)
    {
        int cnt=0;
        re(j,1,n)
            cnt+=dis[i][j]*v[j];
        ans=min(ans,cnt);
    }
    pri(ans);
    return 0;
}
