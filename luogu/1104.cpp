#include <bits/stdc++.h>
using namespace std;

int n;
struct man
{
    string name;
    int y,m,d;
}m[105];

bool cmp(man a,man b)
{
    if(a.y!=b.y)
        return a.y<b.y;
    else
    {
        if(a.m!=b.m)
            return a.m<b.m;
        else
        {
            if(a.d!=b.d)
                return a.d<b.d;
            else
                return true;
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>m[i].name>>m[i].y>>m[i].m>>m[i].d;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(cmp(m[j],m[i]))
                swap(m[j],m[i]);
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<m[i].name;
        if(i!=n-1)
            cout<<endl;
    }
    return 0;
}
