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
#define pb(a) push_back(a)
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
#define pu(a) push(a)
#define pp() pop()
#define f() front()
#define b() back()
#define prc(a) printf("%c",a)
using namespace std;
const int maxn=300000;
typedef long long ll;

int n,tmp;
deque<int> dq;
stack<int> s;
vector<char> v;

int main()
{
    sci(n);
    fo(i,0,n)
    {
        sci(tmp);
        dq.pb(tmp);
    }
    if(dq.front()>dq.back())
    {
        s.pu(dq.back());
        dq.pop_back();
        v.pb('R');
    }
    else
    {
        s.pu(dq.front());
        dq.pop_front();
        v.pb('L');
    }
    while(dq.size()>1)
    {
        if(dq.front()<s.top()&&dq.back()<s.top())
            break;
        else
        {
            if(dq.f()>s.top()&&dq.b()>s.top())
            {
                if(dq.f()<dq.b())
                {
                    s.pu(dq.f());
                    dq.pop_front();
                    v.pb('L');
                }
                else if(dq.b()<dq.f())
                {
                    s.pu(dq.b());
                    dq.pop_back();
                    v.pb('R');
                }
            }
            else if(dq.f()>s.top()&&dq.b()<s.top())
            {
                s.pu(dq.f());
                dq.pop_front();
                v.pb('L');
            }
            else if(dq.f()<s.top()&&dq.b()>s.top())
            {
                s.pu(dq.b());
                dq.pop_back();
                v.pb('R');
            }
        }
    }
    if(dq.f()>s.top())
        v.pb('R');
    pri(v.size());
    prn();
    fo(i,0,v.size())
        prc(v[i]);
    return 0;
}
