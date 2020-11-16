#include <bits/stdc++.h>
using namespace std;

int n;
string ans[20005];

void init(int n)
{
    vector<int> v;
    for(int i=20;i>=0;--i){
        if(n&(1<<i))
            v.push_back(i);
    }
    string tmp="";
    for(int i=0;i<v.size();++i){
        if(v[i]>1){
            tmp+="2("+ans[v[i]]+")+";
        }
        else if(v[i]==1){
            tmp+=ans[1]+"+";
        }
        else if(v[i]==0){
            tmp+=ans[0]+"+";
        }
    }
    if(tmp[tmp.length()-1]=='+')
        tmp.erase(tmp.length()-1,1);
    ans[n]=tmp;
}

int main()
{
    cin>>n;
    ans[0]="2(0)";
    ans[1]="2";
    for(int i=2;i<=n;++i)
        init(i);
    cout<<ans[n];
    return 0;
}
