#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define sci(a) scanf("%d",&a)
#define scll(a) scanf("%lld",&a)
#define scc(a) scanf("%c",&a)
#define pb(a) push_back(a)
#define prti(a) printf("%d\n",a)
#define prtll(a) printf("%lld\n",a)
using namespace std;
typedef long long ll;
const int Max=100000;
const ll mod=998244353;

int n;

bool cmp(const int& a,const int& b)
{
    return a>b;
}

int minswap(vector<int> init,vector<int> dest)
{
    map<int,int> m;
    _for(i,0,n)
        m[dest[i]]=i;
    int loop=0;
    vector<bool> isask(n,false);
    _for(i,0,n)
    {
        if(!isask[i])
        {
            int j=i;
            while(!isask[j])
            {
                isask[j]=true;
                j=m[init[j]];///让当前进行验证的下标等于该数应该处于的下标
            }
            loop++;
        }
    }
    return n-loop;
}

int main()
{
    sci(n);
    vector<int> a(n),b(n),ta(n),tb(n),A(n),B(n);
    map<int,int> ma,mb;
    _for(i,0,n)
    {
        sci(a[i]);
        ta[i]=a[i];
    }
    _for(i,0,n)
    {
        sci(b[i]);
        tb[i]=b[i];
    }
    sort(tb.begin(),tb.end());
    sort(ta.begin(),ta.end(),cmp);
    _for(i,0,n)
    {
        ma[ta[i]]=tb[i];
        mb[tb[i]]=ta[i];
    }
    _for(i,0,n)
    {
        A[i]=mb[b[i]];
        B[i]=ma[a[i]];
    }
    /*
    _for(i,0,n)
        cout<<A[i]<<" ";
    cout<<endl;
    _for(i,0,n)
        cout<<B[i]<<" ";
    cout<<endl;
    */
    /*
    prti(minswap(a,A));
    prti(minswap(b,B));
    */
    prti(min(minswap(a,A),minswap(b,B)));
    return 0;
}
