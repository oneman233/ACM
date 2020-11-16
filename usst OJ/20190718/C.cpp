#include <bits/stdc++.h>
using namespace std;

int n,a[100005];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    vector<int> pos;
    for(int i=1;i<=n;++i)
        if(a[i]!=i)
            pos.push_back(i);
    if(pos.size()==0)
    {
        cout<<"0 0";
        return 0;
    }
    int x=pos[0],y=pos[pos.size()-1];
    reverse(a+x,a+y+1);
    /*
    for(int i=1;i<=n;++i)
        cout<<a[i]<<' ';
    */
    bool can=true;
    for(int i=1;i<=n;++i){
        if(a[i]!=i){
            can=false;
            break;
        }
    }
    if(can)
        cout<<x<<' '<<y;
    else
        cout<<"No";
    return 0;
}
