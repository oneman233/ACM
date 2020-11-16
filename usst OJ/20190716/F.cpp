#include <bits/stdc++.h>
using namespace std;

string s;
int t;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        int cntb=0,cntp=0;
        for(int i=0;i<s.length();++i)
        {
            if(s[i]=='B')
                cntb++;
            else if(s[i]=='.')
                cntp++;
        }
        if(s.length()==1)
        {
            printf("Yes\n");
            continue;
        }
        if(cntb<cntp||cntb==0||cntp==0)
        {
            printf("No\n");
            continue;
        }
        printf("Yes\n");
    }
    return 0;
}
