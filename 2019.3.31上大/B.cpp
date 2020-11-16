#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int Max=100000;

int main()
{
    int n;
    char a;
    map<char,int> m;
    cin>>n;
    _for(i,0,26)
    {
        cin>>a;
        m[a]=i;
    }
    string b,c;
    while(n--)
    {
        bool flag=true;
        cin>>b>>c;
        _for(i,0,min(b.length(),c.length()))
        {
            if(m[b[i]]>m[c[i]])
            {
                flag=false;
                cout<<">"<<endl;
                break;
            }
            else if(m[b[i]]<m[c[i]])
            {
                flag=false;
                cout<<"<"<<endl;
                break;
            }
            else;
        }
        if(flag)
        {
            if(b.length()<c.length())
                cout<<"<"<<endl;
            else if(b.length()>c.length())
                cout<<">"<<endl;
            else
                cout<<"="<<endl;
        }
    }
    return 0;
}
