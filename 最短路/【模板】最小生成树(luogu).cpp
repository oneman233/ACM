#include <bits/stdc++.h>
using namespace std;

int n,m,pre[5010];
int ans=0,cnt=1;
///记录权值之和以及目前并查集中的边数
struct pic
{
    int x,y,z;
}p[200010];

bool cmp(pic a,pic b)
{
    return a.z<b.z;
}
///把边按照权值由小到大排序

int f(int x)
{
    if(x==pre[x])
        return x;
    else
    {
        pre[x]=f(pre[x]);
        ///路径压缩
        return f(pre[x]);
    }
}

void kruskal()
{
    int le,re;
    sort(p,p+m,cmp);
    for(int i=0;i<m;++i)
    {
        le=f(p[i].x);
        re=f(p[i].y);
        if(le==re)
        ///如果左节点所属的并查集分支
        ///与右节点所属的并查集分支终点一致
        ///这意味着左右节点已经被联通
        ///根据贪心的原理，此时不再需要联通它们
            continue;
        ans+=p[i].z;
        pre[le]=re;
        cnt++;
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
    int x,y,z;
    for(int i=0;i<m;++i)
    {
        cin>>x>>y>>z;
        p[i].x=x;
        p[i].y=y;
        p[i].z=z;
    }
    kruskal();
    cout<<ans;
    return 0;
}
