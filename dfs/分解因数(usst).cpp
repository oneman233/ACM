#include <bits/stdc++.h>
using namespace std;

int dfs(int nn,int m)
{
    if(m==1)
        return 0;///���п��ܵ����Ӷ��㶨��
    if(nn==1)
        return 1;///���������⵽ֻʣ�±�����
    if(nn%m==0)
        return dfs(nn,m-1)+dfs(nn/m,m);
    return dfs(nn,m-1);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<dfs(n,n)<<endl;
    }
    return 0;
}
