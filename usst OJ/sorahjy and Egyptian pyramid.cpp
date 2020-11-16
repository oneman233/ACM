#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,k;//计数器
    int dif=0;//不同的段数
    unsigned long long n;//字符串长度
    string s1,s2;
    cin>>n;
    cin>>s1;
    cin>>s2;
    if(s1==s2)//每个都一样
    {
        cout<<(n+1)*n/2;
        return 0;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(s1[i]==s2[i])
                break;
        }
        if(i==n)//每个都不一样
        {
            cout<<(n-1)*2;
            return 0;
        }
        else
        {
            i=0;
            int len=0;//不同的字符串的长度
            while(i<n)
            {
                if(s1[i]!=s2[i])
                {
                    dif++;
                    if(dif==3)
                    {
                        cout<<0;
                        return 0;
                    }
                    while(s1[i]!=s2[i])
                    {
                        i++;
                        len++;
                    }
                    continue;
                }
                i++;
            }
            if(dif==2)
            {
                cout<<6;
                return 0;
            }
            else
            {
                cout<<(len-1)*2+(n-len)*2;
            }
        }
    }
    return 0;
}
