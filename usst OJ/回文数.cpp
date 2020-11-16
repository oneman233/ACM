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
const int maxn=300000;
typedef long long ll;

int n,cnt=0;
string s;
map<char,int> ci;
map<int,char> ic;

bool chk()
{
    string ts="";
    for(int i=s.length()-1;i>=0;--i)
        ts.append(1,s[i]);
    if(s==ts)
        return true;
    else
        return false;
}

void add()
{
    string ts="";
    for(int i=s.length()-1;i>=0;--i)
        ts.append(1,s[i]);
    vector<int> vs,vts;
    for(int i=0;i<s.length();++i)
        vs.push_back(ci[s[i]]);
    for(int i=0;i<ts.length();++i)
        vts.push_back(ci[ts[i]]);
    vector<int> ans;
    for(int i=vs.size()-1;i>=0;--i)
        ans.push_back(vs[i]+vts[i]);
    for(int i=ans.size()-1;i>=1;--i){
        if(ans[i]>=n){
            ans[i-1]+=ans[i]/n;
            ans[i]%=n;
        }
    }
    if(ans[0]>=n){
        ans.insert(ans.begin(),ans[0]/n);
        ans[1]%=n;
    }
    string tmp="";
    for(int i=0;i<ans.size();++i)
        tmp.append(1,ic[ans[i]]);
    s=tmp;
}

int main()
{
    cin>>n>>s;
    for(char i='A';i<='Z';++i)
        ci[i]=10+i-'A',ic[10+i-'A']=i;
    for(char i='0';i<='9';++i)
        ci[i]=i-'0',ic[i-'0']=i;
    while(!chk()){
        add();
        cnt++;
        if(cnt>=30)
            break;
    }
    if(cnt>=30)
        cout<<"Impossible!";
    else
        cout<<"STEP="<<cnt;
    return 0;
}
