#include <bits/stdc++.h>
using namespace std;

int aa[5][5];

int main()
{
    for(int i=0;i<=4;++i)
        aa[i][i]=0;
    aa[0][1]=-1;
    aa[0][2]=1;
    aa[0][3]=1;
    aa[0][4]=-1;
    aa[1][2]=-1;
    aa[1][3]=1;
    aa[1][4]=-1;
    aa[2][3]=-1;
    aa[2][4]=1;
    aa[3][4]=1;
    for(int i=4;i>=1;--i){
        for(int j=0;j<i;++j){
            aa[i][j]=-aa[j][i];
        }
    }
    int n,na,nb,tmp;
    vector<int> a,b;
    cin>>n>>na>>nb;
    for(int i=0;i<na;++i){
        cin>>tmp;
        a.push_back(tmp);
    }
    for(int i=0;i<nb;++i){
        cin>>tmp;
        b.push_back(tmp);
    }
    int idx=0;
    while(a.size()<n){
        a.push_back(a[idx]);
        idx++;
    }
    idx=0;
    while(b.size()<n){
        b.push_back(b[idx]);
        idx++;
    }
    int as=0,bs=0;
    for(int i=0;i<n;++i){
        if(aa[a[i]][b[i]]==1)
            as++;
        else if(aa[a[i]][b[i]]==-1)
            bs++;
    }
    cout<<as<<" "<<bs;
    return 0;
}
