#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int tmp;
    int ans=10000;
    for(int a=0;a<=10;++a)
    {
        for(int b=0;b<=10;++b)
        {
            for(int c=0;c<=10;++c)
            {
                for(int d=0;d<=10;++d)
                {
                    for(int e=0;e<=10;++e)
                    {
                        for(int f=0;f<=10;++f)
                        {
                            tmp=10;
                            tmp+=a*100;
                            tmp+=b*10;
                            tmp+=c;
                            if(tmp>999)
                                tmp=999;
                            tmp-=d*100;
                            tmp-=e*10;
                            tmp-=f;
                            if(tmp<0)
                                tmp=0;
                            if(tmp==n)
                            {
                                ans=min(ans,(a+b+c+d+e+f));
                            }
                        }

                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
