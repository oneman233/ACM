#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k;
ll sum,a[105];
ll max2=-100;
vector<ll> tmp,ans;

void dfs(int i,ll he,ll he2)
{
    /*
    for(auto i:tmp)
        cout<<i<<" ";
    cout<<he<<" "<<he2<<endl;
    */
    if(i>n)
        return;
    if(he==sum&&tmp.size()==k&&he2>max2){
        max2=he2;
        ans.clear();
        for(int i=0;i<tmp.size();++i)
            ans.push_back(tmp[i]);
        return;
    }
    if(he+a[i]<=sum){
        tmp.push_back(a[i]);
        dfs(i+1,he+a[i],he2+a[i]*a[i]);
        tmp.pop_back();
    }
    dfs(i+1,he,he2);
}

int main()
{
    scanf("%d %d %lld",&n,&k,&sum);
    for(int i=0;i<n;++i)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    dfs(0,0,0);
    printf("%lld\n",max2);
    for(int i=0;i<ans.size();++i)
        printf("%d ",ans[i]);
    return 0;
}
