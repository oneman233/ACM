#include <bits/stdc++.h>
using namespace std;
const int inf=-0x3f3f3f3f;

int n,m,ans=inf;
int a[15][20];
struct p
{
    int l,r;
    p(int a,int b):l(a),r(b){}
    void pri(){cout<<l<<' '<<r<<endl;}
};
vector<p> out,tmp;

void ansout()
{
    cout<<ans<<endl;
    if(out.size()<n){
        int flg=out.size()+1;
        while(out.size()<n){
            out.push_back(p(flg,0));
            flg++;
        }
    }
    for(int i=0;i<(int)out.size();++i)
        out[i].pri();
}

void dfs(int x,int cost,int sum)
{
    if(x>n)
        return;
    if(sum>ans){
        ans=sum;
        out=tmp;
    }
    for(int i=0;i<=m-cost;++i){
        tmp.push_back(p(x+1,i));
        dfs(x+1,cost+i,sum+a[x+1][i]);
        tmp.pop_back();
    }
}

int main()
{
    memset(a,0,sizeof(a));
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>a[i][j];
    for(int i=0;i<=m;++i){
        tmp.push_back(p(1,i));
        dfs(1,i,a[1][i]);
        tmp.pop_back();
    }
    ansout();
    return 0;
}
