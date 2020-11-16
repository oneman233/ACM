#include <bits/stdc++.h>
using namespace std;
const int maxn=30005;

int t;
int p[maxn],ft[maxn],bk[maxn];
char c;
int x,y;

int fi(int x)
{
    if(x!=p[x]){
        int pr=p[x];
        int fa=fi(p[x]);
        p[x]=fa;
        ft[x]+=ft[pr]-1;

    }
    return p[x];
}

void me(int x,int y)
{
    int rx=fi(x);
    int ry=fi(y);
    if(rx!=ry){
        p[rx]=ry;
        ft[rx]+=bk[ry];
        bk[ry]+=bk[rx];
    }
}

int main()
{
    for(int i=1;i<=30000;++i){
        p[i]=i;
        ft[i]=1;
        bk[i]=1;
    }
    cin>>t;
    while(t--){
        cin>>c>>x>>y;
        if(c=='M')
            me(x,y);
        else if(c=='C'){
            if(x==y){
                printf("0\n");
                continue;
            }
            int rx=fi(x);
            int ry=fi(y);
            if(rx!=ry)
                printf("-1\n");
            else
                printf("%d\n",max(ft[x],ft[y])-min(ft[x],ft[y])-1);
        }
    }
    return 0;
}
