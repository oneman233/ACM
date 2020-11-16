#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,temp;
    __INT64_MAX__ ans=0;
    cin>>n>>m;
    vector<vector<int> > v(n,vector<int>(m));
    /*含有n个元素，每个元素含有一个长为m的int型向量*/
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>temp;
            v[i][j]=temp;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans+=min(v[j][0],v[j][v[j].size()-1])*(1<<i);
            if(v[j][0]>=v[j][v[j].size()-1])
                v[j].pop_back();
            else
                v[j].erase(v[j].begin());
        }
    }
    cout<<ans;
    return 0;
}
