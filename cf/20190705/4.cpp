#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define scs(a) scanf("%s",a)
#define scii(a,b) scanf("%d%d",&a,&b)
#define sci(a) scanf("%d",&a)
#define scll(a,b) scanf("%lld%lld",&a,&b)
#define scl(a) scanf("%lld",&a)
#define prd(a) printf("%lf",a)
#define prc(a) printf("%c",a)
#define prs(a) printf("%s",a)
#define pri(a) printf("%d",a)
#define prl(a) printf("%lld",a)
#define prn() printf("\n")
#define pub(a) push_back(a)
#define pob() pop_back()
#define puf(a) push_front(a)
#define pof() pop_front()
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
#define endl "\n"
#define debug(a) cout<<a<<endl
using namespace std;
typedef long long ll;
const ll maxn=500005;
const ll inf=0x3f3f3f3f;
const double pi=3.1415926535;
const double esp=1e-10;
const int mod=10007;
template <typename t>
t mmax(t a,t b,t c){return max(a,max(b,c));}
template <typename t>
t mmin(t a,t b,t c){return min(a,min(b,c));}

int n,a;
priority_queue<int> pq;
deque<int> d;

int l(int x)
{
    if(x!=0)
        return x-1;
    return n-1;
}

int r(int x)
{
    if(x!=n-1)
        return x+1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    fo(i,0,n)
    {
        cin>>a;
        pq.push(a);
    }
    d.pub(pq.top());
    pq.pop();
    while(!pq.empty()){
        if(d.front()>=d.back())
            d.puf(pq.top());
        else
            d.pub(pq.top());
        pq.pop();
    }
    bool can=true;
    fo(i,0,n)
    {
        if(d[i]>=d[l(i)]+d[r(i)]){
            can=false;
            break;
        }
    }
    if(can){
        cout<<"YES"<<endl;
        fo(i,0,n)
            cout<<d[i]<<' ';
    }
    else
        cout<<"NO";
    return 0;
}
