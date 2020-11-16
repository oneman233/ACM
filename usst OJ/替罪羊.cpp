#include <bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;
const int maxn=300005;
const int inf=0x3f3f3f3f;

int n,tmp;
vector<int> son[maxn];
int tag[maxn],d[maxn];

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>tmp,tag[i]=tmp;
    for(int i=2;i<=n;++i){
        cin>>tmp;
        son[tmp].pb(i);
    }
    int k=0;
    for(int i=n;i>=1;--i){
        if(son[i].size()==0)
            d[i]=1,k++;
        else if(son[i].size()!=0){
            if(tag[i]==1){
                d[i]=inf;
                for(int j=0;j<son[i].size();++j)
                    d[i]=min(d[i],d[son[i][j]]);
            }
            else if(tag[i]==0){
                d[i]=0;
                for(int j=0;j<son[i].size();++j)
                    d[i]+=d[son[i][j]];
            }
        }
    }
    cout<<k-d[1]+1;
    return 0;
}
