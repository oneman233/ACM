#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,x,y;
int a[1001][1001];
ll sum=0;

int main()
{
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>a[i][j];
            if(a[i][j]==-1)
                x=i,y=j;
            else
                sum+=a[i][j];
        }
    }
    int tx,ty;
    if(x>0){
        tx=x-1;
        if(y>0)
            ty=y-1;
        else
            ty=y+1;
    }
    else{
        tx=x+1;
        if(y>0)
            ty=y-1;
        else
            ty=y+1;
    }
    a[x][y]=a[tx][y]+a[x][ty]-a[tx][ty];
    cout<<a[x][y]<<" "<<(sum+a[x][y])/n;
    return 0;
}
