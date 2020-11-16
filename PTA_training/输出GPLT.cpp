#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    map<char,int> m;
    int ci=10000;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='g'||s[i]=='G')
            m['G']++;
        if(s[i]=='p'||s[i]=='P')
            m['P']++;
        if(s[i]=='l'||s[i]=='L')
            m['L']++;
        if(s[i]=='t'||s[i]=='T')
            m['T']++;
    }
    int flag=0;
    while(ci--)
    {
        if(flag==0)
        {
            if(m['G']>0)
            {
                cout<<"G";
                m['G']--;
            }
        }
        else if(flag==1)
        {
            if(m['P']>0)
            {
                cout<<"P";
                m['P']--;
            }
        }
        else if(flag==2)
        {
            if(m['L']>0)
            {
                cout<<"L";
                m['L']--;
            }
        }
        else
        {
            if(m['T']>0)
            {
                cout<<"T";
                m['T']--;
            }
        }
        flag++;
        if(flag==4)
            flag=0;
    }
    return 0;
}
