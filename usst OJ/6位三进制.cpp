#include <bits/stdc++.h>

using namespace std;

bool isprime(int a)
{
    if(a==2||a==3||a==5||a==7||a==11)
        return true;
    else
        return false;
}

int main()
{
    int l,r;
    int ans=0;
    cin>>l>>r;
    for(int a=0;a<=2;a++)
    {
        for(int b=0;b<=2;b++)
        {
            for(int c=0;c<=2;c++)
            {
                for(int d=0;d<=2;d++)
                {
                    for(int e=0;e<=2;e++)
                    {
                        for(int f=0;f<=2;f++)
                        {
                            if(isprime(a+b+c+d+e+f)||((a+b+c+d+e+f)>=l&&(a+b+c+d+e+f)<=r))
                                ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
