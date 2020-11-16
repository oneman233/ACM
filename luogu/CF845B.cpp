#include <bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;

string s;
int a[6],ans=0;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    cin>>s;
    for(int i=0;i<6;++i)
        a[i]=s[i]-'0';
    int qian=a[0]+a[1]+a[2];
    int hou=a[3]+a[4]+a[5];
    if(qian==hou){
        cout<<0;
        return 0;
    }
    else{
        vector<int> cha;
        if(qian<hou){
            for(int i=0;i<3;++i)
                cha.pb(9-a[i]);
            for(int i=3;i<6;++i)
                cha.pb(a[i]);
        }
        else{
            for(int i=0;i<3;++i)
                cha.pb(a[i]);
            for(int i=3;i<6;++i)
                cha.pb(9-a[i]);
        }
        sort(cha.begin(),cha.end(),cmp);
        int cnt=1;
        int dif=max(qian,hou)-min(qian,hou);
        for(int i=0;i<6;++i){
            if(dif<=cha[i])
                break;
            dif-=cha[i];
            cnt++;
        }
        cout<<cnt;
    }
    return 0;
}
/*
888999
*/
