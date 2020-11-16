#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define sci(a) scanf("%d",&a)
#define pri(a) printf("%d",a)
using namespace std;
typedef long long ll;

int main()
{
    string s;
    string com[5];
    cin>>s;
    _for(i,0,5)
        cin>>com[i];
    bool can=false;
    _for(i,0,5)
    {
        if(s[0]==com[i][0]||s[1]==com[i][1])
        {
            can=true;
            break;
        }
    }
    if(can)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
