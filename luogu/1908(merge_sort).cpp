#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define scii(a,b) scanf("%d%d",&a,&b)
#define sci(a) scanf("%d",&a)
#define scll(a,b) scanf("%lld%lld",&a,&b)
#define scl(a) scanf("%lld",&a)
#define pri(a) printf("%d",a)
#define prl(a) printf("%lld",a)
#define prn() printf("\n")
#define pu(a) push_back(a)
#define po() pop_back()
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
using namespace std;
const int maxn=500000;
typedef long long ll;

int a[maxn],tmp[maxn],n;
ll ans=0;

void mer(int l,int r)
{
    if(l>=r)
        return;
    int mid=(l+r)>>1;
    mer(l,mid);
    mer(mid+1,r);
    ///分
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j]){
            tmp[k]=a[i];
            ++i;
            ++k;
        }
        else{
            tmp[k]=a[j];
            ++j;
            ++k;
            ///产生了逆序对
            ///即右边的数据小于左边的数据
            ///此时左边的小区间是有序的
            ///于是只需要考虑左边区间从i开始一共有几个数字即可！
            ///这意味着j交换到它应该在的位置上去的时候需要移动多少步
            ans+=(mid-i+1);
        }
    }
    while(i<=mid){
        tmp[k]=a[i];
        ++i;
        ++k;
    }
    while(j<=r){
        tmp[k]=a[j];
        ++j;
        ++k;
    }
    for(int i=l;i<=r;++i)
        a[i]=tmp[i];
}

inline int read()
{
    char ch=getchar();
    int x=0,f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}

int main()
{
    n=read();
    re(i,1,n)
        a[i]=read();
    mer(1,n);
    prl(ans);
    return 0;
}
