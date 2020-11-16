#include <bits/stdc++.h>
using namespace std;

int main()
{
    double len=0.0,er=0.0;
    string n;
    cin>>n;
    for(int i=0;i<n.length();i++)
    {
        if(n[i]!='-')
            len+=1.0;
        if(n[i]=='2')
            er+=1.0;
    }
    double ans=er/len;
    if(n[0]=='-')
        ans*=1.5;
    if((n[n.length()-1]-'0')%2==0)
        ans*=2.0;
    printf("%.2lf%%",ans*100);
    return 0;
}
