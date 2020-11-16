#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

int main()
{
    map<char,int> m;
    string a,b,c,d;
    getline(cin,a);
    getline(cin,b);
    getline(cin,c);
    getline(cin,d);
    _for(i,0,a.length())
        m[a[i]]++;
    _for(i,0,b.length())
        m[b[i]]++;
    _for(i,0,c.length())
        m[c[i]]++;
    _for(i,0,d.length())
        m[d[i]]++;
    int high=0;
    for(char i='A';i<='Z';i++)
        high=max(high,m[i]);
    char ans[high+1][26];
    char temp='A';
    _for(i,0,26)
    {
        ans[high][i]=temp;
        temp++;
    }
    for(int i=high-1;i>=0;i--)
    {
        temp='A';
        _for(j,0,26)
        {
            if(m[temp]!=0)
            {
                ans[i][j]='*';
                m[temp]--;
            }
            else
                ans[i][j]=' ';
            temp++;
        }
    }
    _for(i,0,high+1)
    {
        _for(j,0,26)
        {
            cout<<ans[i][j];
            if(j==25&&i!=high)
                cout<<endl;
            else
                cout<<" ";
        }
    }
    return 0;
}
