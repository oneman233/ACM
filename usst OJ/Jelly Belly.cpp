#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define scc(a) scanf("%c",&a)
#define scs(a) scanf("%s",a)
#define scii(a,b) scanf("%d%d",&a,&b)
#define sci(a) scanf("%d",&a)
#define scll(a,b) scanf("%lld%lld",&a,&b)
#define scl(a) scanf("%lld",&a)
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
using namespace std;
const int MAX=500000;
const int inf=0x3f3f3f3f;
typedef long long ll;
template <typename t>
t mmax(t a,t b,t c){return max(a,max(b,c));}
template <typename t>
t mmin(t a,t b,t c){return min(a,min(b,c));}

int n,l,r;
char tmp,ans[MAX];
deque<char> j,b;

int main()
{
    sci(n);
    getchar();
    fo(i,0,n/2)
    {
        scc(tmp);
        j.pub(tmp);
    }
    getchar();
    fo(i,0,n/2)
    {
        scc(tmp);
        b.pub(tmp);
    }
    sort(j.begin(),j.end());
    sort(b.begin(),b.end(),greater<char>());
    l=0,r=n-1;
    while(!j.empty()&&!b.empty()){
        if(j.front()>=b.front()){
            ans[r]=j.back();
            r--;
            j.pob();
        }
        else{
            ans[l]=j.front();
            l++;
            j.pof();
        }
        if(b.front()<=j.front()){
            ans[r]=b.back();
            r--;
            b.pob();
        }
        else{
            ans[l]=b.front();
            l++;
            b.pof();
        }
    }
    fo(i,0,n)
        prc(ans[i]);
    return 0;
}
/*
4
cc
aa
*/
