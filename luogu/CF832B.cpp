#include <bits/stdc++.h>
using namespace std;

string good;
map<char,int> m;
string t,s;
int n;

void pre()
{

}

void work()
{

}

int main()
{
    cin>>good;
    for(int i=0;i<(int)good.length();++i)
        m[good[i]]=1;
    cin>>t;
    pre();
    cin>>n;
    while(n--){
        cin>>s;
        work();
    }
    return 0;
}
