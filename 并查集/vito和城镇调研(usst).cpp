#include <bits/stdc++.h>
using namespace std;

int n,m;
int pre[1005];

int findr(int x)
{
    if(x==pre[x])
        return x;
    else
    {
        pre[x]=findr(pre[x]);///·��ѹ��
        return findr(pre[x]);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        pre[i]=i;
    ///��ʼ��
    int tempx,tempy;
    for(int i=0;i<m;++i)
    {
        cin>>tempx>>tempy;
        pre[findr(max(tempx,tempy))]=findr(min(tempx,tempy));
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        if(pre[i]==i)
            ++ans;
    }
    cout<<ans-1;
    ///ֻ��Ҫ�����еĸ�����һ���ok
    return 0;
}
