#include <bits/stdc++.h>
using namespace std;

int n,m;
int ans=0,cnt=1;
struct pic
{
    int x,y,t;
}p[100010];
int pre[1010];

int f(int x)
{
    if(x==pre[x])
        return x;
    else
    {
        pre[x]=f(pre[x]);
        return pre[x];
        ///路径压缩
    }
}

bool cmp(pic a,pic b)
{
    return a.t<b.t;
}

void kruskal()
{
    sort(p,p+m,cmp);
    int le,re;
    for(int i=0;i<m;++i)
    {
        le=f(p[i].x);
        re=f(p[i].y);
        if(le==re)
            continue;
        ans=max(ans,p[i].t);
        ///更新答案贡献
        pre[le]=re;
        ///连接无向图
        cnt++;
        ///节点数更新
        if(cnt==n)
            break;
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        pre[i]=i;
    ///init
    int x,y,t;
    for(int i=0;i<m;++i)
    {
        cin>>x>>y>>t;
        p[i].x=x;
        p[i].y=y;
        p[i].t=t;
    }
    kruskal();
    if(cnt!=n)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
