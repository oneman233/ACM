#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;

int n,m,pos,mx=0,my=0;
int a1,b1,a2,b2,a3,b3;
char c;
int x[maxn],y[maxn],sx[maxn],sy[maxn];

inline int mmax(int a,int b,int c)
{
    return max(a,max(b,c));
}

inline int mmin(int a,int b,int c)
{
    return min(a,min(b,c));
}

inline void difx(int a,int b)
{
    x[a+1]++;
    x[b]--;
}

inline void dify(int a,int b)
{
    y[a+1]++;
    y[b]--;
}

void build()
{
    sx[0]=x[0];
    for(int i=1;i<=mx;++i)
        sx[i]=x[i]+sx[i-1];
    sy[0]=y[0];
    for(int i=1;i<=my;++i)
        sy[i]=y[i]+sy[i-1];
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d %d %d %d %d %d",&a1,&b1,&a2,&b2,&a3,&b3);
        mx=max(mx,mmax(a1,a2,a3));
        difx(mmin(a1,a2,a3),mmax(a1,a2,a3));
        my=max(my,mmax(b1,b2,b3));
        dify(mmin(b1,b2,b3),mmax(b1,b2,b3));
    }
    build();
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        getchar();
        getchar();
        scanf("%c = %d",&c,&pos);
        if(c=='x')
            printf("%d\n",sx[pos]);
        else if(c=='y')
            printf("%d\n",sy[pos]);
    }
    return 0;
}
