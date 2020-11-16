#include <bits/stdc++.h>
using namespace std;

int n,m;
int p[1005][1005],s[1005][1005];

void f(int &a)
{
    a=1-a;
}

bool chk(int i,int j)
{
    if(i<1||i>n||j<1||j>m)
        return false;
    return true;
}

void chg(int i,int j)
{
    f(p[i][j]);
    if(chk(i+1,j))
        f(p[i+1][j]);
    if(chk(i-1,j))
        f(p[i-1][j]);
    if(chk(i,j+1))
        f(p[i][j+1]);
    if(chk(i,j-1))
        f(p[i][j-1]);
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            cin>>s[i][j],p[i][j]=1;
            if(s[i][j]&1)
                s[i][j]=1;
            else
                s[i][j]=0;
        }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(s[i][j])
                chg(i,j);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)
            cout<<p[i][j];
        cout<<endl;
    }
    return 0;
}
