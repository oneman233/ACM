#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;

int n,l,r;
map<int,int> m;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d %d",&l,&r);
        m[l]++;
        m[r+1]--;
    }
    int cnt=0;
    for(auto i=m.begin();i!=m.end();++i){
        cnt+=i->second;
        if(cnt>2){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
