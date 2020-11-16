#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;

struct point
{
    int i,j;
    bool operator == (const point &p)
    {
        if(this->i==p.i&&this->j==p.j)
            return true;
        else
            return false;
    }
    point (int i,int j)
    {
        this->i=i;
        this->j=j;
    }
    point (){}
}s,e;

int ans=inf;
string ss,se;
int x[8]={1,1,2,2,-1,-1,-2,-2};
int y[8]={2,-2,1,-1,2,-2,1,-1};
int num[100];
bool vis[100][100];

int h(point p)
{
    return p.i*10+p.j;
}

bool chk(point p)
{
    if(p.i>=0&&p.i<=8&&p.j>=0&&p.j<=8&&vis[p.i][p.j]==false)
        return true;
    else
        return false;
}

void bfs()
{
    deque<point> d;
    d.push_back(s);
    vis[s.i][s.j]=true;
    while(!d.empty()){
        if(num[h(d.front())]>ans)
            break;
        if(d.front()==e)
            ans=min(ans,num[h(d.front())]);
        point tmp[8];
        for(int k=0;k<8;++k)
            tmp[k]=point(d.front().i+x[k],d.front().j+y[k]);
        for(int k=0;k<8;++k)
            if(chk(tmp[k])){
                d.push_back(tmp[k]);
                vis[tmp[k].i][tmp[k].j]=true;
                num[h(tmp[k])]=num[h(d.front())]+1;
            }
        d.pop_front();
    }
}

void init()
{
    ans=inf;
    memset(num,0,sizeof(num));
    memset(vis,0,sizeof(vis));
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        init();
        cin>>ss>>se;
        s.i=ss[0]-'A';
        s.j=ss[1]-'1';
        e.i=se[0]-'A';
        e.j=se[1]-'1';
        bfs();
        cout<<ans<<endl;
    }
    return 0;
}
