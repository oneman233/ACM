#include <bits/stdc++.h>
using namespace std;

int n,m,x,y;
char c;
int p[2005];

int fi(int x)
{
    if(x!=p[x])
        p[x]=fi(p[x]);
    return p[x];
}

void me(int x,int y)
{
    int rx=fi(x);
    int ry=fi(y);
    if(rx!=ry)
        p[rx]=ry;
}

int main()
{
    cin>>n;
    for(int i=1;i<=2*n;++i)
        p[i]=i;
    cin>>m;
    while(m--){
        cin>>c>>x>>y;
        if(c=='E'){
            me(x,y+n);
            me(x+n,y);
        }
        else if(c=='F'){
            me(x,y);
        }
    }
    set<int> s;
    for(int i=1;i<=n;++i)
        s.insert(fi(i));
    cout<<s.size();
    return 0;
}
