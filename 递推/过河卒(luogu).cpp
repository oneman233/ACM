#include <bits/stdc++.h>
using namespace std;

int xb,yb,xm,ym;
long long way[25][25];

bool ok(int x,int y)
{
    if(x<0||x>xb||y<0||y>yb)
        return false;
    if(abs(x-xm)==2&&abs(y-ym)==1)
        return false;
    if(abs(x-xm)==1&&abs(y-ym)==2)
        return false;
    if(x==xm&&y==ym)
        return false;
    return true;
}

int main()
{
    cin>>xb>>yb>>xm>>ym;
    way[0][0]=1;
    for(int i=0;i<=xb;++i){
        for(int j=0;j<=yb;++j){
            if(ok(i+1,j))
                way[i+1][j]+=way[i][j];
            if(ok(i,j+1))
                way[i][j+1]+=way[i][j];
        }
    }
    cout<<way[xb][yb];
    return 0;
}
///ok函数很神必
