#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define sci(a) scanf("%d",&a)
#define pri(a) printf("%d",a)
using namespace std;
typedef long long ll;

bool f(string s)
{
    set<char> che;
    int len=s.length();
    _for(i,0,len)
    {
        che.insert(s[i]);
    }
    if(che.size()!=len)
    {
        return false;
    }
    else
    {
        if(len==1)
            return true;
        else
        {
            char c,s=*(che.begin()),e;
            set<char>::iterator it;
            for(it=che.begin();it!=che.end();++it)
                e=*(it);
            for(c=s;c<=e;++c)
            {
                if(!che.count(c))
                    return false;
            }
            return true;
        }
    }
}

int main()
{
    int n;
    sci(n);
    string s;
    _for(i,0,n)
    {
        cin>>s;
        if(f(s))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
