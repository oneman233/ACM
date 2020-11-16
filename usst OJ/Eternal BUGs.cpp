#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _rep(i,a,b) for(int i=(a);i<=(b);i++)
#define _rrep(i,a,b) for(int i=(a);i>=(b);i++)

const long long INF=0x3f3f3f3f;
using namespace std;

int main()
{
    string pat;
    vector<int> vx,vy;
    int t,x=0,y=0,tempx,tempy;;
    cin>>pat;
    vx.push_back(0);
    vy.push_back(0);
    for(int i=0;i<pat.length();i++)
    {
        if(pat[i]=='L')
            x--;
        else if(pat[i]=='R')
            x++;
        else if(pat[i]=='U')
            y++;
        else if(pat[i]=='D')
            y--;
        vx.push_back(x);
        vy.push_back(y);
    }

    for(int i=0;i<vx.size();i++)
        cout<<vx[i]<<" "<<vy[i]<<endl;

    cin>>t;
    while(t--)
    {
        cin>>tempx>>tempy;
        tempx%=x;
        tempy%=y;
        bool lock=true;
        for(int i=0;i<vx.size();i++)
        {
            if(tempx==vx[i]&&tempy==vy[i])
            {
                lock=false;
                cout<<"Yes"<<endl;
            }
        }
        if(lock)
            cout<<"No"<<endl;
    }
    return 0;
}
