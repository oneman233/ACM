#include <bits/stdc++.h>
#define sci(a) scanf("%d",&a)
#define prl(a) printf("%lld",a)
#define _rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
const int maxn=500000;

int n,tr[maxn+5];
struct discontinity
{
    int pos;
    int val;
}a[maxn+5];

int lowbit(int i)
{
    return i&-i;
}

void add(int i)
{
    while(i<=n)
    {
        tr[i]+=1;
        i+=lowbit(i);
    }
}

ll sum(int i)
{
    ll ans=0;
    while(i>=1)
    {
        ans+=tr[i];
        i-=lowbit(i);
    }
    return ans;
}

bool cmp(const discontinity &a,const discontinity &b)
{
    return a.val>=b.val;
    ///val大的尽量放前面
}

int main()
{
    sci(n);
    _rep(i,1,n)
    {
        sci(a[i].val);
        a[i].pos=i;
    }
    stable_sort(a+1,a+1+n,cmp);///必须稳定排序
    /*
    _rep(i,1,n)
        cout<<a[i].pos<<" ";
    cout<<endl;
    */
    ll ans=0;
    _rep(i,1,n)
    {
        add(a[i].pos);
        ///cout<<sum(a[i].pos-1)<<endl;
        ans+=sum(a[i].pos-1);
    }
    prl(ans);
    return 0;
}
