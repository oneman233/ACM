#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    bool del[10005];
    for(int i=0;i<10005;i++)
        del[i]=false;
    //初始化属实要命
    for(int i=0;i<b.length();i++)
    {
        for(int j=0;j<a.length();j++)
        {
            if(a[j]==b[i])
                del[j]=true;
        }
    }
    for(int i=0;i<a.length();i++)
    {
        if(!del[i])
            cout<<a[i];
    }
    return 0;
}
