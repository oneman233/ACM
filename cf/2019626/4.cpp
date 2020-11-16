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

bool can=false;
ll n,k;
string s;
unordered_map<string,int> m;
set<string> ss;
int ans=0;

void bfs()
{
    queue<string> q;
    q.push(s);
    m[s]=1;
    ss.insert(s);
    if(ss.size()>=k){
        can=true;
        return;
    }
    while(!q.empty()){
        //cout<<ans<<' '<<q.size()<<endl;
        if(q.front().length()>1){
            for(int i=1;i<=q.front().length()-2;++i)
                if(m[q.front().substr(0,i)+q.front().substr(i+1,q.front().length()-i-1)]!=1){
                    q.push(q.front().substr(0,i)+q.front().substr(i+1,q.front().length()-i-1));
                    m[q.front().substr(0,i)+q.front().substr(i+1,q.front().length()-i-1)]=1;
                }
            if(m[q.front().substr(1,q.front().length()-1)]!=1){
                q.push(q.front().substr(1,q.front().length()-1));
                m[q.front().substr(1,q.front().length()-1)]=1;
            }
            if(m[q.front().substr(0,q.front().length()-1)]!=1){
                q.push(q.front().substr(0,q.front().length()-1));
                m[q.front().substr(0,q.front().length()-1)]=1;
            }
        }
        else if(q.front().length()==1&&m[""]!=1){
            q.push("");
            m[""]=1;
        }
        /*
        if(m[q.front()]!=0){
            q.pop();
            continue;
        }
        */
        //m[q.front()]=1;
        //cout<<q.front()<<endl;
        ss.insert(q.front());
        ans+=n-q.front().length();
        if(ss.size()>=k){
            can=true;
            return;
        }
        q.pop();
    }
    if(ss.size()>=k){
        can=true;
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    cin>>s;
    bfs();
    //cout<<ss.size()<<endl;
    if(can)
        cout<<ans;
    else
        cout<<-1;
    return 0;
}
/*
100 100
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/
