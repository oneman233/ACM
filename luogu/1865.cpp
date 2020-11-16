#include <bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;
const int maxm=1000000;

int n,m;
bool isprime[maxm+10];
int ans[maxm+10];
vector<int> v;

void get()
{
    for(int i=1;i<=m;++i)
        isprime[i]=true;
    isprime[0]=isprime[1]=false;
    for(int i=2;i<=m;++i)
    {
        if(isprime[i])
            v.pb(i);
        for(int j=0;j<v.size()&&i*v[j]<=m;++j)
        {
            isprime[i*v[j]]=false;
            if(i%v[j]==0)
                break;
        }
    }
    memset(ans,0,sizeof(ans));
    ans[0]=ans[1]=0;
    int idx=0;
    for(int i=2;i<=m;++i)
    {
        if(i==v[idx])
        {
            ans[i]=ans[i-1]+1;
            idx++;
        }
        else
            ans[i]=ans[i-1];
    }
}

int main()
{
    cin>>n>>m;
    int x,y;
    get();
    while(n--)
    {
        cin>>x>>y;
        if(x>=1&&y<=m)
            cout<<ans[y]-ans[x-1]<<endl;
        else
            cout<<"Crossing the line"<<endl;
    }
    return 0;
}
