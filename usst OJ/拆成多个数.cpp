#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
typedef long long ll;
const int Max=1000000;

int main()
{
    string s;
    cin>>s;
    map<char,int> m;
    for(char i='0';i<='9';++i)
        m[i]=i-'0';
    for(char i='A';i<='V';++i)
        m[i]=i-'A'+10;
    int ans=0;
    for(int i=s.length()-1;i>=0;--i)
    {
        int cnt=0,temp=m[s[i]];
        while(temp)
        {
            if(temp%2!=0)
                cnt++;
            temp/=2;
        }
        ans+=cnt;
    }
    cout<<ans;
    return 0;
}
