#include <bits/stdc++.h>
using namespace std;

int n;
int a[4005],ans=0;
map<int,int> m;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<n;++i){
        m[a[i]]++;
        int cnt=0;
        bool can=false;
        for(auto j=m.begin();j!=m.end();++j){
            if(j->second>=2)
                cnt++;
            if(cnt==2||j->second==4){
                can=true;
                break;
            }
        }
        if(can){
            ans++;
            m.clear();
        }
    }
    printf("%d",ans);
    return 0;
}
