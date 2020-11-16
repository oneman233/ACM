#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][m],b[n][m];
    int hang[n],lie[m];
    memset(hang,0,sizeof(hang));
    memset(lie,0,sizeof(lie));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>b[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(a[i][j]!=b[i][j])
                hang[i]++,lie[j]++;
        }
    }
    for(int i=0;i<n;++i){
        if(hang[i]&1){
            cout<<"No";
            return 0;
        }
    }
    for(int i=0;i<m;++i){
        if(lie[i]&1){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}
