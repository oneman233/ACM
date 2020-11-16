#include <bits/stdc++.h>
using namespace std;

int h1,a1,c1,h2,a2;
vector<string> ans;
void da()
{
    ans.push_back("STRIKE");
}
void he()
{
    ans.push_back("HEAL");
}

int main()
{
    cin>>h1>>a1>>c1>>h2>>a2;
    while(h2>0){
        if(a1>=h2){
            da();
            break;
        }
        if(h1>a2){
            da();
            h1-=a2;
            h2-=a1;
        }
        else{
            he();
            h1+=c1;
            h1-=a2;
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)
        cout<<i<<endl;
    return 0;
}
