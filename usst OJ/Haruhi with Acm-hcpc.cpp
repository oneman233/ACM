#include <bits/stdc++.h>
using namespace std;
const int inf=-0x3f3f3f3f;

int n,m,h;
int x,y,judge,z;
struct team
{
    string name;
    int question,punish,last;
    int wa[20],time[20];
    team()
    {
        question=0;
        punish=0;
        last=inf;
        memset(wa,0,sizeof(wa));
        memset(time,0,sizeof(time));
    }
    void cal()
    {
        for(int i=1;i<=m;++i){
            if(time[i]>=0){
                question++;
                last=max(last,time[i]);
                punish+=20*wa[i]+time[i];
            }
        }
    }
}t[1005];
string tp;

bool cmp(team a,team b)
{
    if(a.question==b.question){
        if(a.punish==b.punish){
            return a.last<b.last;
        }
        else return a.punish<b.punish;
    }
    else return a.question>b.question;
}

int toi(string s)
{
    if(s=="+")
        return 0;
    if(s[0]=='0')
        return 0;
    else if(s[0]=='+'||s[0]=='-'){
        s.erase(0,1);
        return stoi(s);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        getchar();
        getline(cin,t[i].name);
        for(int j=1;j<=m;++j){
            cin>>tp;
            t[i].wa[j]=toi(tp);
        }
        for(int j=1;j<=m;++j)
            cin>>t[i].time[j];
    }
    cin>>h;
    while(h--){
        cin>>x>>y>>judge>>z;
        if(t[x].time[y]>=0)
            continue;
        if(judge==1) t[x].time[y]=z;
        else if(judge==0) t[x].wa[y]++;
    }
    for(int i=1;i<=n;++i)
        t[i].cal();
    sort(t+1,t+1+n,cmp);
    for(int i=1;i<=n;++i)
        cout<<t[i].name<<" "<<t[i].question<<" "<<t[i].punish<<endl;
    return 0;
}
