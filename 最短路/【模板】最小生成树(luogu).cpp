#include <bits/stdc++.h>
using namespace std;

int n,m,pre[5010];
int ans=0,cnt=1;
///��¼Ȩֵ֮���Լ�Ŀǰ���鼯�еı���
struct pic
{
    int x,y,z;
}p[200010];

bool cmp(pic a,pic b)
{
    return a.z<b.z;
}
///�ѱ߰���Ȩֵ��С��������

int f(int x)
{
    if(x==pre[x])
        return x;
    else
    {
        pre[x]=f(pre[x]);
        ///·��ѹ��
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
        ///�����ڵ������Ĳ��鼯��֧
        ///���ҽڵ������Ĳ��鼯��֧�յ�һ��
        ///����ζ�����ҽڵ��Ѿ�����ͨ
        ///����̰�ĵ�ԭ����ʱ������Ҫ��ͨ����
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
