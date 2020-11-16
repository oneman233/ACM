#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1000005;

int lowbit(int x){return x&-x;}
struct query
{
    int ix,l,r;
    bool operator <(query &q)
    {
        if(r!=q.r)
            return r<q.r;
        else
            return l<q.l;
    }
}q[maxn];
int qq,pre[maxn];
int n,a[maxn],tr[maxn];
int ans[maxn];

void add(int pos,int x)
{
    for(int i=pos;i<=n;i+=lowbit(i))
        tr[i]+=x;
}
int sum(int pos)
{
    int ans=0;
    for(int i=pos;i>=1;i-=lowbit(i))
        ans+=tr[i];
    return ans;
}

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    scanf("%lld",&qq);
    for(int i=0;i<qq;++i){
        scanf("%lld %lld",&q[i].l,&q[i].r);
        q[i].ix=i;
    }
    sort(q,q+qq);
    int qflag=0;
    for(int i=1;i<=n;++i)
    {
        if(pre[a[i]]!=0)
            add(pre[a[i]],-1);
        add(i,1);
        pre[a[i]]=i;
        while(q[qflag].r==i){
            ans[q[qflag].ix]=sum(q[qflag].r)-sum(q[qflag].l-1);
            qflag++;
            if(qflag>=qq)
                break;
        }
    }
    for(int i=0;i<qq;++i)
        printf("%lld\n",ans[i]);
    return 0;
}
