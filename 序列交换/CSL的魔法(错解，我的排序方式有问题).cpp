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

int n,read;
vector<int> a,b;

vector<int> getb()
{
    vector<int> tempb(b),tempa(a),out(n,0);
    sort(tempb.begin(),tempb.end());
    _for(i,0,n)
    {
        int big=0,idx;
        _for(j,0,n)
        {
            if(tempa[j]>big)
            {
                big=tempa[j];
                idx=j;
            }
        }
        out[idx]=tempb[i];
        tempa[idx]=0;
    }
    return out;
}


vector<int> geta()
{
    vector<int> tempb(b),tempa(a),out(n,0);
    sort(tempa.begin(),tempa.end());
    _for(i,0,n)
    {
        int big=0,idx;
        _for(j,0,n)
        {
            if(tempb[j]>big)
            {
                big=tempb[j];
                idx=j;
            }
        }
        out[idx]=tempa[i];
        tempb[idx]=0;
    }
    return out;
}


int minswap(vector<int> v,vector<int> ov)
///由序列v变成序列ov的最少交换次数
{
    map<int,int> m;
    int len=v.size();
    _for(i,0,len)
        m[ov[i]]=i;
    int loop=0;
    vector<bool> isask(len,false);
    _for(i,0,len)
    {
        if(!isask[i])
        {
            int j=i;
            while(!isask[j])
            {
                isask[j]=true;
                j=m[v[i]];
            }
            loop++;
        }
    }
    return len-loop;
}

int main()
{
    sci(n);
    _for(i,0,n)
    {
        sci(read);
        a.pb(read);
    }
    _for(i,0,n)
    {
        sci(read);
        b.pb(read);
    }
    prti(min(minswap(b,getb()),minswap(a,geta())));
    return 0;
}
