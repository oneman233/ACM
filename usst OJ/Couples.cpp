#include <bits/stdc++.h>

using namespace std;

int n,m;
struct man
{
    char c;
    int p;
    man(char cc,int pp)
    {
        c=cc;
        p=pp;
    }
};
deque<man> a,b;
char tmp;
deque<int> flaga,flagb;
vector<int> weia,weib;
vector<int> px,py;

bool cmp(man x,man y)
{
    return x.c<y.c;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>tmp;
        if(tmp=='?')
        {
            flaga.push_back(i);
        }
        else
        {
            man haha(tmp,i);
            a.push_back(haha);
        }
    }
    for(int i=1;i<=m;++i)
    {
        cin>>tmp;
        if(tmp=='?')
        {
            flagb.push_back(i);
        }
        else
        {
            man haha(tmp,i);
            b.push_back(haha);
        }
    }
    sort(a.begin(),a.end(),cmp);
    sort(b.begin(),b.end(),cmp);
    while(!a.empty()&&!b.empty())
    {
        if(a.front().c==b.front().c)
        {
            px.push_back(a.front().p);
            py.push_back(b.front().p);
            a.pop_front();b.pop_front();
        }
        while(!a.empty()&&a.front().c<b.front().c)
        {
            weia.push_back(a.front().p);
            a.pop_front();
        }
        while(!b.empty()&&b.front().c<a.front().c)
        {
            weib.push_back(b.front().p);
            b.pop_front();
        }
    }
    while(!a.empty())
    {
        weia.push_back(a.front().p);
        a.pop_front();
    }
    while(!b.empty())
    {
        weib.push_back(b.front().p);
        b.pop_front();
    }
    ///cout<<weia.size()<<" "<<flagb.size()<<endl;
    for(int i=0;i<weib.size()&&!flaga.empty();++i)
    {
        px.push_back(flaga.front());
        py.push_back(weib[i]);
        flaga.pop_front();
    }
    for(int i=0;i<weia.size()&&!flagb.empty();++i)
    {
        px.push_back(weia[i]);
        py.push_back(flagb.front());
        flagb.pop_front();
    }
    while(!flaga.empty()&&!flagb.empty())
    {
        px.push_back(flaga.front());
        py.push_back(flagb.front());
        flaga.pop_front();
        flagb.pop_front();
    }
    cout<<min(px.size(),py.size())<<endl;
    for(int i=0;i<min(px.size(),py.size());++i)
    {
        cout<<px[i]<<" "<<py[i];
        if(i!=px.size()-1)
            cout<<endl;
    }
    return 0;
}
