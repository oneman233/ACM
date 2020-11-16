#include <bits/stdc++.h>
using namespace std;

set<int> s[55];

double check(int a,int b)
{
    int left=a-1;
    int right=b-1;
    set<int> big;
    set<int>::iterator it;
    for(it=s[left].begin();it!=s[left].end();it++)
        big.insert(*it);
    for(it=s[right].begin();it!=s[right].end();it++)
        big.insert(*it);
    double fenmu=0.0;
    for(int i=0;i<big.size();i++)
        fenmu+=1.0;
    return (s[left].size()+s[right].size()-big.size())/fenmu;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        int temp;
        for(int j=0;j<m;j++)
        {
            cin>>temp;
            s[i].insert(temp);
        }
    }
    double ans[55][55];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ans[i][j]=check(i,j);
        }
    }
    int k;
    cin>>k;
    while(k--)
    {
        int p,q;
        cin>>p>>q;
        printf("%.2lf%%\n",ans[p][q]*100);
    }
    return 0;
}
