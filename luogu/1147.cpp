#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    stack<int> sa,sb;
    cin>>m;
    m*=2;
    for(int i=2;i*i<=m;++i)
    {
        if(m%i==0)
        {
            int j=m/i;
            if((i+j-1)%2==0)
            {
                int b=(i+j-1)/2;
                int a=j-b;
                sa.push(a);
                sb.push(b);
            }
        }
    }
    while(!sa.empty()&&!sb.empty())
    {
        cout<<sa.top()<<" "<<sb.top()<<endl;
        sa.pop();sb.pop();
    }
    return 0;
}
