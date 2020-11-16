#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int ans=0,temp;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        temp=1;
        for(int j=1;j<len;j++)
        {
            if(i-j<0||i+j>=len||s[i+j]!=s[i-j])
                break;
            temp+=2;
        }
        ans=(temp>ans?temp:ans);
        temp=0;
        for(int j=1;j<len;j++)
        {
            if(i-j+1<0||i+j>=len||s[i-j+1]!=s[i+j])
                break;
            temp+=2;
        }
        ans=(temp>ans?temp:ans);
    }
    cout<<ans;
    return 0;
}
