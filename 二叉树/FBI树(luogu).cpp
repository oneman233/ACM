#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int n;
string s;

char check(int l,int e)
{
    map<char,int> m;
    for(int i=l;i<=e;++i)
        m[s[i]]++;
    if(m['0']!=0&&m['1']!=0)
        return 'F';
    else if(m['0']==0)
        return 'I';
    else
        return 'B';
}

void build(int l,int e)
{
    ///cout<<l<<" "<<e<<endl;
    if(l>e)
        return;
    if(l==e)
    {
        cout<<check(l,e);
        return;
    }
    ///只剩一个的时候已经递归到底，不需要再递归
    build(l,(l+e)/2);
    build((l+e)/2+1,e);
    cout<<check(l,e);
}

int main()
{
    cin>>n;
    cin>>s;
    build(0,s.length()-1);
    return 0;
}
