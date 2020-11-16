// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;

struct Stu
{
    int p,s,yu;
}stu[100000];

bool cmp(Stu a,Stu b)
{
    if(a.s!=b.s)
        return a.s>b.s;
    else
    {
        if(a.yu!=b.yu)
            return a.yu>b.yu;
        else
            return a.p<b.p;
    }
}

int main()
{
    int n;
    int a,b,c;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a>>b>>c;
        stu[i].p=i;
        stu[i].s=a+b+c;
        stu[i].yu=a;
    }
    sort(stu+1,stu+1+n,cmp);
    for(int i=1;i<=5;++i)
        cout<<stu[i].p<<" "<<stu[i].s<<endl;
}
