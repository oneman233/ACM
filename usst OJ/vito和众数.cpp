#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,num,max_num=0;
    map<int,int> m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        m[num]++;
    }
    for(int i=0;i<=20000;i++)
    {
        if(m[i]>max_num)
        {
            max_num=m[i];
            num=i;
        }
    }
    cout<<num<<" "<<max_num;
    return 0;
}
