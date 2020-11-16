#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
ll a[100010];
struct tree
{
    int l,r;
    ll v,tag;
}tr[400010];

inline int ls(int p){return p*2;}
inline int rs(int p){return p*2+1;}
void up(int p){tr[p].v=tr[ls(p)].v+tr[rs(p)].v;}
///三个函数
///求leftson和rightson
///更新父节点的值，它由左右孩子的值决定

void build(int p,int l,int r)
{
    tr[p].l=l;tr[p].r=r;
    if(l==r)
    {
        tr[p].v=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    ///前序遍历建立线段树
    ///用mid值划分区间
    up(p);
    ///更新父节点
}

///lazy标记是记录每次每个节点需要更新的值
///它用于这样的情况
///目前我需要修改1-9区间的值
///我就只修改1-9区间，并且给它打上一个tag
///下一次修改比1-9更小的区间时候，再把tag下放
///保证每一次修改都起到了作用
///但是注意lazy标记下放之后一定要清零，否则高处的懒标记会影响区间查询

void down(int p)
{
    if(tr[p].tag!=0)
    {
        tr[ls(p)].v+=tr[p].tag*(tr[ls(p)].r-tr[ls(p)].l+1);
        tr[rs(p)].v+=tr[p].tag*(tr[rs(p)].r-tr[rs(p)].l+1);
        ///此处我不太明白，跟左右区间的值有什么关系？
        ///这意味着左右儿子节点上每个值都需要修改tag大小的值
        ///所以是求一个乘积，并且区间个数为r-l+1
        tr[ls(p)].tag+=tr[p].tag;
        tr[rs(p)].tag+=tr[p].tag;
        ///把tag下放
        tr[p].tag=0;
        ///父节点的tag清零
    }
}

void change(int p,int x,int y,ll z)
{
    if(x<=tr[p].l&&y>=tr[p].r)
    {
        tr[p].v+=z*(tr[p].r-tr[p].l+1);
        tr[p].tag+=z;
        return;
    }
    ///如果某个区间被需要修改的区间所覆盖
    ///那么直接对它进行修改并且打上tag
    down(p);
    ///如果未被覆盖，那就需要先把父节点的tag下放
    ///之后再去儿子节点中修改
    int mid=(tr[p].l+tr[p].r)/2;
    if(x<=mid)
        change(ls(p),x,y,z);
    if(y>mid)
        change(rs(p),x,y,z);
    ///如果[x,y]区间与[tr[p].l,tr[p].r]区间有重合部分
    ///那么就向下修改他们
    up(p);
    ///更新父节点
}

long long ask(int p,int x,int y)
{
    if(x<=tr[p].l&&y>=tr[p].r)
        return tr[p].v;
    ///如果当前区间被查询区间覆盖，就直接返回对应值
    ///是为了累加到树的更高层，也就是更大的子区间那里去
    ///作为那个区间的返回值
    ///实际上是“分解”了[x,y]区间，逐层向下寻找答案
    ///一路上还要下放lazy标记
    down(p);
    int mid=(tr[p].l+tr[p].r)/2;
    ll ans=0;
    if(x<=mid)
        ans+=ask(ls(p),x,y);
    if(y>mid)
        ans+=ask(rs(p),x,y);
    ///与上面同理
    return ans;

}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    build(1,1,n);///树的第一个节点存储着整个区间的值
    while(m--)
    {
        int judge;
        scanf("%d",&judge);
        if(judge==1)
        {
            int x,y;
            ll k;
            scanf("%d %d %lld",&x,&y,&k);
            change(1,x,y,k);
            ///永远从头节点开始修改
        }
        else if(judge==2)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            printf("%lld\n",ask(1,x,y));
        }
    }
    return 0;
}
