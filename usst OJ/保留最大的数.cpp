#include <bits/stdc++.h>

using namespace std;

int main()
{
    string num;
    int cnt;
    cin>>num;
    cin>>cnt;
    while(cnt--)
    {
        int i;
        bool lock=true;
        for(i=0;i<num.length()-1;i++)
        {
            if(num[i]>=num[i+1])
                continue;
            num.erase(i,1);
            lock=false;
            break;
        }
        if(lock)
            num.erase(num.length()-1,1);
    }
    cout<<num;
    return 0;
}
