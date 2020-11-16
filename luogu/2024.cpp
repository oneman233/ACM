#include <iostream>
using namespace std;
const int maxn=150005;

int n,m,ans=0;
int p[maxn];

int fa(int x)
{
    if(x!=p[x])
        p[x]=fa(p[x]);
    return p[x];
}

void same(int x,int y)
{
    if(y>n||x>n){
        ans++;
        return;
    }
    if(x==y)
        return;
    int rx=fa(x);
    int rxn=fa(x+n);
    int rx2n=fa(x+2*n);
    int ry=fa(y);
    int ryn=fa(y+n);
    int ry2n=fa(y+2*n);
    if(rx==ryn||ry==rxn){
        ans++;
        return;
    }
    p[rx]=ry;
    p[rxn]=ryn;
    p[rx2n]=ry2n;
}

void eat(int x,int y)
{
    if(y>n||x>n||x==y){
        ans++;
        return;
    }
    int rx=fa(x);
    int rxn=fa(x+n);
    int rx2n=fa(x+2*n);
    int ry=fa(y);
    int ryn=fa(y+n);
    int ry2n=fa(y+2*n);
    if(rx==ry||ry==rxn){
        ans++;
        return;
    }
    p[rx]=ryn;
    p[rxn]=ry2n;
    p[rx2n]=ry;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=3*n;++i)
        p[i]=i;
    while(m--){
        int judge,x,y;
        scanf("%d %d %d",&judge,&x,&y);
        if(judge==1)
            same(x,y);
        else if(judge==2)
            eat(x,y);
    }
    printf("%d",ans);
    return 0;
}
