#include <bits/stdc++.h>
#define sci(a) scanf("%d",&a)
#define scii(a,b) scanf("%d%d",&a,&b)
#define no printf("Warning\n")
#define yes printf("Ok\n")
using namespace std;
const int maxn=2000;

int t,n,m,a,b;
int pre[2*maxn+5];

void init()
{
    for(int i=1;i<=2*n;++i)
        pre[i]=i;
}

inline int root(int x)
{
    if(x==pre[x])
        return x;
    /*
    else
    {
        pre[x]=root(pre[x]);
        return pre[x];
    }
    */
    return root(pre[x]);
}

inline void meg(int x,int y)
{
    pre[root(x)]=root(y);
}

inline bool chk(int x,int y)
{
    int xr=root(x);
    int yr=root(y);
    if(xr==yr)
        return true;
    else
        return false;
}

int main()
{
    sci(t);
    while(t--)
    {
        bool can=true;
        scii(n,m);
        init();
        while(m--)
        {
            scii(a,b);
            if(!can)
                continue;
            /*
            if(pre[x]==x&&pre[y+n]==y+n){
                pre[x]=y+n;pre[y+n]=x;continue;
            }
            if(pre[x+n]==x+n&&pre[y]==y){
                pre[x+n]=y;pre[y]=x+n;continue;
            }
            */
            /*
            no;
            can=false;
            break;
            */
            meg(a,b+n);
            meg(a+n,b);
            if(chk(a,a+n)||chk(b,b+n))///
            {
                can=false;
                no;
                ///break;
            }
        }
        if(can)
            yes;
        /*
        for(int i=1;i<=2*n;++i)
            cout<<pre[i]<<" ";
        cout<<endl;
        */
    }
    return 0;
}
