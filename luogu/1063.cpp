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

int main()
{
    map<string,int> m;
    m["zero"]=0;
    m["one"]=1;
    m["two"]=2;
    m["three"]=3;
    m["four"]=4;
    m["five"]=5;
    m["six"]=6;
    m["seven"]=7;
    m["eight"]=8;
    m["nine"]=9;
    m["ten"]=10;
    m["eleven"]=11;
    m["twelve"]=12;
    m["thirteen"]=13;
    m["fourteen"]=14;
    m["fifteen"]=15;
    m["sixteen"]=16;
    m["seventeen"]=17;
    m["eighteen"]=18;
    m["nineteen"]=19;
    m["twenty"]=20;
    m["a"]=1;
    m["both"]=2;
    m["another"]=1;
    m["first"]=1;
    m["second"]=2;
    m["third"]=3;
    int cnt=0;
    string s;
    vector<int> v;
    _for(i,0,6)
    {
        cin>>s;
        if(s=="zero")
        {
            v.pb(0);
            ++cnt;
        }
        else if(m[s]!=0)
        {
            v.pb(m[s]);
            ++cnt;
        }
        else;
    }
    if(cnt==0)
        cout<<"0";
    else
    {
        _for(i,0,v.size())
        {
            v[i]*=v[i];
            v[i]%=100;
        }
        vector<string> v0;
        _for(i,0,v.size())
        {
            stringstream ss;
            string temp;
            ss<<v[i];
            ss>>temp;
            v0.pb(temp);
        }
        _for(i,0,v0.size())
            if(v0[i].length()==1)
                v0[i].insert(v0[i].begin(),'0');
        sort(v0.begin(),v0.end());
        string out="";
        _for(i,0,v0.size())
            out+=v0[i];
        int i=0;
        while(out[i]=='0')
            ++i;
        _for(j,i,out.length())
            cout<<out[j];
    }
    return 0;
}
