#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mkp(a,b) make_pair(a,b)
#define vec vector<pair<int,int> >
#define pr pair<int,int>
#define fs first
#define sc second
using namespace std;

int t,n;
int a[100];

bool overlap(pr a,pr b)
{
    if(a.fs>b.fs&&a.fs<b.sc&&a.sc>b.sc)
        return false;
    if(a.sc>b.fs&&a.sc<b.sc&&a.fs<b.fs)
        return false;
    return true;
}

bool chk(vec v,pr p)
{
    for(int i=0;i<v.size();++i){
        if(!overlap(p,v[i]))
            return false;
    }
    return true;
}

int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        map<int,int> m;
        for(int i=1;i<=n;++i)
            m[a[i]]=i;
        bool can=true;
        vec l,r;
        for(int i=1;i<=n-1;++i){
            int s=min(m[i],m[i+1]),e=max(m[i],m[i+1]);
            if(i&1){
                if(!chk(l,mkp(s,e))){
                    can=false;
                    break;
                }
                else l.pb(mkp(s,e));
            }
            else{
                if(!chk(r,mkp(s,e))){
                    can=false;
                    break;
                }
                else r.pb(mkp(s,e));
            }
        }
        if(can)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
