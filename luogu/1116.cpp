#include <bits/stdc++.h>
using namespace std;

int n,ans=0;
int a[10005],b[10005],c[10005];

int lowbit(int x){return x&-x;}

void add(int x,int v)
{
    while(x<=n){
        a[x]+=v;
        x+=lowbit(x);
    }
}

int sum(int x)
{
    int ans=0;
    while(x>=1){
        ans+=a[x];
        x-=lowbit(x);
    }
    return ans;
}

bool cmp(const int &a,const int &b)
{
    return a>b;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>b[i],c[b[i]]=i;
    ///稳定排序是为了防止有相同元素的情况，这可能导致答案出错
    stable_sort(b+1,b+1+n,cmp);
    ///可在此处改变插入顺序
    for(int i=1;i<=n;++i){
        add(c[b[i]],1);
        ans+=sum(c[b[i]]-1);
    }
    cout<<ans;
    return 0;
}
