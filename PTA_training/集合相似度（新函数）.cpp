#include <bits/stdc++.h>
using namespace std;

set<int> s[55];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int m,temp;
        cin>>m;
        for(int j=0;j<m;j++)
        {
            cin>>temp;
            s[i].insert(temp);
        }
    }
    int k;
    cin>>k;
    while(k--)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        set<int> jiao;
        set_intersection(s[a].begin(),s[a].end(),s[b].begin(),s[b].end(),inserter(jiao,jiao.begin()));
        double nc=jiao.size();
        double nt=s[a].size()+s[b].size()-jiao.size();
        printf("%.2lf%%\n",100.0*nc/nt);
    }
    return 0;
}
