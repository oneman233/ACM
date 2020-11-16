#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a=1,b=1;
    string star,group;
    cin>>star;
    cin>>group;
    for(int i=0;i<star.length();i++)
        a*=star[i]-'A'+1;
    for(int i=0;i<group.length();i++)
        b*=group[i]-'A'+1;
    if(a%47==b%47)
        cout<<"GO";
    else
        cout<<"STAY";
    return 0;
}
