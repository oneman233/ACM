#include <bits/stdc++.h>
using namespace std;

int n;
string s="";

int r(int x)
{
    if(x==n-1)
        return 0;
    return x+1;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        s.append(1,'0');
    cout<<n<<endl;
    int flag=1;
    int tmp=n;
    while(tmp--){
        int cnt=n-1,i=flag;
        while(cnt--){
            if(s[i]=='0')
                s[i]='1';
            else
                s[i]='0';
            i=r(i);
        }
        flag=r(flag);
        cout<<s<<endl;
    }
    return 0;
}
