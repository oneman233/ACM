#include <bits/stdc++.h>

using namespace std;

int main()
{
    char pic;
    int n;
    while(cin>>pic)
    {
        if(pic=='@')
            break;
        cin>>n;
        for(int i=0;i<n-1;i++)
            cout<<" ";
        cout<<pic<<endl;/*first*/
        int space=1;
        for(int i=2;i<=n-1;i++)
        {
            for(int j=0;j<n-i;j++)
                cout<<" ";
            cout<<pic;
            for(int j=0;j<space;j++)
                cout<<" ";
            cout<<pic;
            space+=2;
            cout<<endl;
        }/*mid*/
        for(int i=0;i<2*n-1;i++)
            cout<<pic;/*last*/
        cout<<"\n"<<endl;
    }
    return 0;
}
