#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;

int n,a,flg=1;
vector<int> v;

int main()
{
    scanf("%d",&n);
    while(n--){
        scanf("%d",&a);
        auto pos=lower_bound(v.begin(),v.end(),a);
        v.insert(pos,a);
        if(v.size()==flg){
            printf("%d\n",v[v.size()/2]);
            flg+=2;
        }
    }
    return 0;
}
