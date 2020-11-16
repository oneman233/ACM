#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
    cin>>n;
    cin>>s;
    /*
    int cnt=0,len=0;
    for(int i=0;i<n;++i)
        if(s[i]!='8')
            len++;///到8的距离
    for(int i=0;i<n;++i)
        if(s[i]=='8')
            cnt++;///8的个数
    */
    int cha=n-11;
    int tmp=cha/2;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='8'&&tmp)
        {
            s[i]='d';
            tmp--;
        }
        if(tmp==0)
            break;
    }
    int len=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]!='8'&&s[i]!='d')
            len++;
        if(s[i]=='8')
            break;
    }
    if(len>cha/2)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
