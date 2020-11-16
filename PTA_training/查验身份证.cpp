#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int problem=0;
    cin>>n;
    while(n--)
    {
        bool nonum=false;
        string s;
        cin>>s;
        for(int i=0;i<17;i++)
        {
            if(s[i]<'0'||s[i]>'9')
            {
                nonum=true;
                break;
            }
        }
        if(nonum)
        {
            cout<<s<<endl;
            problem++;
            continue;
        }
        int sum=0;
        int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
        char check[11]={'1','0','X','9','8','7','6','5','4','3','2'};
        for(int i=0;i<17;i++)
            sum+=(s[i]-'0')*weight[i];
        sum%=11;
        if(s[17]!=check[sum])
        {
            cout<<s<<endl;
            problem++;
        }
    }
    if(problem==0)
        cout<<"All passed";
    return 0;
}
