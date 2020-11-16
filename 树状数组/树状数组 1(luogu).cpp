#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

const int Max=500000;

int n,m;
int tree[Max+5];
int temp,x,y;

int lowbit(int x)
{
    return x&(-x);
}
void add(int idx,int val)
{
    while(idx<=n)
    {
        tree[idx]+=val;
        idx+=lowbit(idx);
    }
    ///�����޸�
}
int sum(int x)
{
    int ans=0;
    while(x!=0)
    {
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
    ///�������
}

int main()
{
    memset(tree,0,sizeof(tree));
    cin>>n>>m;
    _for(i,1,n+1)
    {
        cin>>temp;
        add(i,temp);
    }
    ///����ʹ��0������lowbit��ʧЧ
    _for(i,0,m)
    {
        cin>>temp>>x>>y;
        if(temp==1)
            add(x,y);
        else
            cout<<sum(y)-sum(x-1)<<endl;
    }
    return 0;
}
