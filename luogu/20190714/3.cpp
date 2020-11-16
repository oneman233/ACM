#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
inline __int128 read()
{
    __int128 x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

inline void write(__int128 x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}

ll bit1[5000005],bit2[5000005],ans=0,tmp=0,tot;
int n,a[5000005],t[5000005];

ll _find(ll x)
{
    return lower_bound(t+1,t+tot+1,x)-t;
}

void add(ll bit[],int x,int y){for(;x<=tot;x+=x&-x) bit[x]+=y;}
ll sum(ll bit[],int x){ll ret=0; for(;x;x-=x&-x) ret+=bit[x]; return ret;}

int main()
{
    memset(bit1,0,sizeof(bit1));
    memset(bit2,0,sizeof(bit2));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),t[i]=a[i];
    sort(t+1,t+n+1);
    tot=unique(t+1,t+n+1)-t-1;
    for(int i=1;i<=n;i++)
        a[i]=_find(a[i]);
    for(int i=n;i;i--)
    {
        tmp+=sum(bit1,a[i]-1)*i;
        add(bit1,a[i],1);
        add(bit2,a[i],i);
    }
    for(int i=n;i;i--)
    {
        ans+=tmp;
        tmp-=sum(bit2,tot)-sum(bit2,a[i]);
        add(bit2,a[i],-i);
    }
    write(ans);
    return 0;
}
