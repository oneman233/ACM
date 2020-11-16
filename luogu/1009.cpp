#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> v;
    cin>>n;
    v.push_back(1);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<v.size();j++)
            v[j]*=i;
        if(v.size()==1&&v[0]>=10)
        {
            v.insert(v.begin(),v[0]/10);
            v[1]%=10;
            continue;
        }
        else if(v.size()==1&&v[0]<10)
            continue;
        else
        {
            int k=0;
            while(v[k]>=10)
            {
                k=0;
                v.insert(v.begin(),v[k]/10);
                k++;
                v[k]%=10;
                for(int j=v.size()-1;j>=1;j--)
                {
                    if(v[j]>=10)
                    {
                        v[j-1]+=v[j]/10;
                        v[j]%=10;
                    }
                }
            }
        }
        int k=0;
        while(v[k]>=10)
        {
            v.insert(v.begin(),v[k]/10);
            k++;
            v[k]%=10;
            for(int j=v.size()-1;j>=1;j--)
            {
                if(v[j]>=10)
                {
                    v[j-1]+=v[j]/10;
                    v[j]%=10;
                }
            }
        }
    }
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
