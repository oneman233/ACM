#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ans=0;
    vector<int> v;
    if(n>30)
    {
        cout<<0;
        return 0;
    }
    for(int a=1;a<=3;a++)
    {
        for(int b=1;b<=3;b++)
        {
            for(int c=1;c<=3;c++)
            {
                for(int d=1;d<=3;d++)
                {
                    for(int e=1;e<=3;e++)
                    {
                        for(int f=1;f<=3;f++)
                        {
                            for(int g=1;g<=3;g++)
                            {
                                for(int h=1;h<=3;h++)
                                {
                                    for(int i=1;i<=3;i++)
                                    {
                                        for(int j=1;j<=3;j++)
                                        {
                                            if(a+b+c+d+e+f+g+h+i+j==n)
                                            {
                                                ans++;
                                                v.push_back(a);
                                                v.push_back(b);
                                                v.push_back(c);
                                                v.push_back(d);
                                                v.push_back(e);
                                                v.push_back(f);
                                                v.push_back(g);
                                                v.push_back(h);
                                                v.push_back(i);
                                                v.push_back(j);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(ans==0)
    {
        cout<<0;
        return 0;
    }
    cout<<ans<<endl;
    for(int cnt=0;cnt<v.size();cnt+=10)
        cout<<v[cnt]<<" "<<v[cnt+1]<<" "<<v[cnt+2]<<" "<<v[cnt+3]<<" "<<v[cnt+4]<<" "<<v[cnt+5]<<" "<<v[cnt+6]<<" "<<v[cnt+7]<<" "<<v[cnt+8]<<" "<<v[cnt+9]<<endl;
    return 0;
}
