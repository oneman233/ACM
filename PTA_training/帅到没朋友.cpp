#include <bits/stdc++.h>
using namespace std;

int fri[100000];
set<int> ans;
vector<int> out;/**/

int main()
{
    int n,k,m;
    for(int i=0;i<100000;i++)
        fri[i]=0;
    cin>>n;
    while(n--)
    {
        cin>>k;
        int temp;
        if(k!=1)
        {
            while(k--)
            {
                cin>>temp;
                fri[temp]++;
            }
        }
        else
            cin>>temp;
    }
    cin>>m;
    int qes,nofri=0;
    while(m--)
    {
        cin>>qes;
        if(fri[qes]==0)
        {
            if(ans.count(qes)==0)
                out.push_back(qes);
            ans.insert(qes);
            nofri++;
        }
    }
    if(nofri==0)
        cout<<"No one is handsome";
    else
    {
        for(int i=0;i<out.size();i++)
        {
            printf("%05d",out[i]);
            if(i!=out.size()-1)
                cout<<" ";
        }
    }
    return 0;
}
