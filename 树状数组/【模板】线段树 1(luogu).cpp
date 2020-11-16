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
///��������
///��leftson��rightson
///���¸��ڵ��ֵ���������Һ��ӵ�ֵ����

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
    ///ǰ����������߶���
    ///��midֵ��������
    up(p);
    ///���¸��ڵ�
}

///lazy����Ǽ�¼ÿ��ÿ���ڵ���Ҫ���µ�ֵ
///���������������
///Ŀǰ����Ҫ�޸�1-9�����ֵ
///�Ҿ�ֻ�޸�1-9���䣬���Ҹ�������һ��tag
///��һ���޸ı�1-9��С������ʱ���ٰ�tag�·�
///��֤ÿһ���޸Ķ���������
///����ע��lazy����·�֮��һ��Ҫ���㣬����ߴ�������ǻ�Ӱ�������ѯ

void down(int p)
{
    if(tr[p].tag!=0)
    {
        tr[ls(p)].v+=tr[p].tag*(tr[ls(p)].r-tr[ls(p)].l+1);
        tr[rs(p)].v+=tr[p].tag*(tr[rs(p)].r-tr[rs(p)].l+1);
        ///�˴��Ҳ�̫���ף������������ֵ��ʲô��ϵ��
        ///����ζ�����Ҷ��ӽڵ���ÿ��ֵ����Ҫ�޸�tag��С��ֵ
        ///��������һ���˻��������������Ϊr-l+1
        tr[ls(p)].tag+=tr[p].tag;
        tr[rs(p)].tag+=tr[p].tag;
        ///��tag�·�
        tr[p].tag=0;
        ///���ڵ��tag����
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
    ///���ĳ�����䱻��Ҫ�޸ĵ�����������
    ///��ôֱ�Ӷ��������޸Ĳ��Ҵ���tag
    down(p);
    ///���δ�����ǣ��Ǿ���Ҫ�ȰѸ��ڵ��tag�·�
    ///֮����ȥ���ӽڵ����޸�
    int mid=(tr[p].l+tr[p].r)/2;
    if(x<=mid)
        change(ls(p),x,y,z);
    if(y>mid)
        change(rs(p),x,y,z);
    ///���[x,y]������[tr[p].l,tr[p].r]�������غϲ���
    ///��ô�������޸�����
    up(p);
    ///���¸��ڵ�
}

long long ask(int p,int x,int y)
{
    if(x<=tr[p].l&&y>=tr[p].r)
        return tr[p].v;
    ///�����ǰ���䱻��ѯ���串�ǣ���ֱ�ӷ��ض�Ӧֵ
    ///��Ϊ���ۼӵ����ĸ��߲㣬Ҳ���Ǹ��������������ȥ
    ///��Ϊ�Ǹ�����ķ���ֵ
    ///ʵ�����ǡ��ֽ⡱��[x,y]���䣬�������Ѱ�Ҵ�
    ///һ·�ϻ�Ҫ�·�lazy���
    down(p);
    int mid=(tr[p].l+tr[p].r)/2;
    ll ans=0;
    if(x<=mid)
        ans+=ask(ls(p),x,y);
    if(y>mid)
        ans+=ask(rs(p),x,y);
    ///������ͬ��
    return ans;

}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    build(1,1,n);///���ĵ�һ���ڵ�洢�����������ֵ
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
            ///��Զ��ͷ�ڵ㿪ʼ�޸�
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
