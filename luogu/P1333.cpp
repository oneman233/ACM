#include <bits/stdc++.h>
#define mkp(a,b) make_pair(a,b)
using namespace std;

int p[500005];
unordered_map<string,int> in,m;
unordered_map<int,int>chk;
string a,b;

int fi(int n)
{
    if(n!=p[n])
        p[n]=fi(p[n]);
    return p[n];
}

void me(int a,int b)
{
    int ra=fi(a);
    int rb=fi(b);
    if(ra!=rb)
        p[ra]=rb;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=1;i<=500000;++i)
        p[i]=i;
    int flg=1;
    while(cin>>a>>b){
        in[a]++;
        in[b]++;
        if(m[a]==0){
            m[a]=flg;
            flg++;
        }
        if(m[b]==0){
            m[b]=flg;
            flg++;
        }
        me(m[a],m[b]);
    }
    bool can=true;
    int cnt=0;
    for(auto i=m.begin();i!=m.end();++i){
        if(in[i->first]&1)
            cnt++;
        chk[fi(m[i->first])]++;
        if(chk.size()>1){
            can=false;
            break;
        }
        if(cnt>2){
            can=false;
            break;
        }
    }
    if(can)
        printf("Possible\n");
    else
        printf("Impossible\n");
    return 0;
}
