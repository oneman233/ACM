#include <bits/stdc++.h>

using namespace std;

bool sushu(int a)
{
    if(a==0||a==1)
        return false;
    for(int i=2;i<sqrt(a);i++)
    {
        if(a%i==0)
            return false;
    }
    return true;
}

int main()
{
    string s;
    cin>>s;
    int a[26];
    int big=0,small=100001;
    memset(a,0,sizeof(a));
    for(int i=0;i<s.length();i++)
        a[s[i]-'a']++;
    for(int i=0;i<26;i++)
    {
        if(a[i]>big)
            big=a[i];
        if(a[i]<small&&a[i]!=0)
            small=a[i];
    }
    if(sushu(big-small))
    {
        cout<<"Lucky Word"<<endl;
        cout<<big-small;
    }
    else
    {
        cout<<"No Answer"<<endl;
        cout<<"0";
    }
    return 0;
}
