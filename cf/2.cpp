#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[505][505];
set<int> s;
vector<int> ans,num;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>a[i][j];
            s.insert(a[i][j]);
        }
    }
    if(n==1)
    {
        bool can=false;
        int an;
        for(int i=1;i<=m;++i)
        {
            if(a[1][i]!=0)
            {
                can=true;
                an=i;
                break;
            }
        }
        if(can)
        {
            cout<<"TAK"<<endl;
            cout<<an;
        }
        else
            cout<<"NIE";
        return 0;
    }
    if(s.size()==1)
        cout<<"NIE";
    else
    {
        int tmp=a[1][1];
        bool isfind=false;
        ans.push_back(1);
        num.push_back(a[1][1]);
        int i;
        for(i=2;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(isfind)
                    break;
                if(a[i][j]!=tmp)
                {
                    isfind=true;
                    ans.push_back(j);
                    num.push_back(a[i][j]);
                    break;
                }
            }
            if(isfind)
                break;
            ans.push_back(1);
            num.push_back(a[i][1]);
        }
        i++;
        for(;i<=n;i++)
        {
            ans.push_back(1);
            num.push_back(a[i][1]);
        }
        int check=0;
        for(int i=0;i<num.size();++i)
        {
            ///cout<<num[i]<<" ";
            check^=num[i];
        }
        if(check!=0)
        {
            cout<<"TAK"<<endl;
            for(int i=0;i<ans.size();++i)
                cout<<ans[i]<<" ";
        }
        else
        {
            cout<<"NIE";
        }
    }
    return 0;
}
