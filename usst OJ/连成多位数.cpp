#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
typedef long long ll;
const int Max=1000000;

bool campare(string i, string j)
{
    return (i+j)>(j+i);
}

int main()
{
    int n;
    cin>>n;
    vector<string> tmp(n, "");
    for(int i=0;i<n;i++)
        cin>>tmp[i];
    sort(tmp.begin(), tmp.end(), campare);
    for(int i=0; i<n; i++)
        cout<<tmp[i];
    cout<<endl;
}
