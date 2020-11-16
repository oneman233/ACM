#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int Max=500000;

int n,t;
string s;

int main()
{
    cin>>t;
    while(t--)
    {
        string now="u";
        int x=0,y=0;
        cin>>n;
        getchar();
        while(n--)
        {
            getline(cin,s);
            if(s[0]=='F')
            {
                int step;
                string steps;
                stringstream ss;
                _rep(i,8,s.length()-1)
                    steps.append(1,s[i]);
                ss<<steps;
                ss>>step;
                if(now=="u")
                    y+=step;
                else if(now=="d")
                    y-=step;
                else if(now=="l")
                    x-=step;
                else if(now=="r")
                    x+=step;
            }
            else if(s[0]=='R')
            {
                if(now=="u")
                    now="r";
                else if(now=="l")
                    now="u";
                else if(now=="r")
                    now="d";
                else if(now=="d")
                    now="l";
            }
            else if(s[0]=='L')
            {
                if(now=="u")
                    now="l";
                else if(now=="l")
                    now="d";
                else if(now=="r")
                    now="u";
                else if(now=="d")
                    now="r";
            }
            else if(s[0]=='B')
            {
                if(now=="u")
                    now="d";
                else if(now=="l")
                    now="r";
                else if(now=="r")
                    now="l";
                else if(now=="d")
                    now="u";
            }
        }
        cout<<x<<" "<<y;
        if(t!=0)
            cout<<endl;
    }
    return 0;
}
