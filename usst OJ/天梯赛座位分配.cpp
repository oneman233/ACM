#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,maxi;
    bool duo=false;
    cin>>n;
    int m[105],sum=0;
    vector<int> v[105];
    for(int i=0;i<n;i++)
    {
        cin>>m[i];
        m[i]*=10;
        sum+=m[i];
    }
    //cout<<sum<<" "<<m[0]<<endl;
    int temp=1;
    while(sum!=0)
    {
        for(int i=0;i<n;i++)
        {
            if(sum==m[i])
            {
                maxi=i;
                duo=true;
                break;
            }
        }
        if(duo)
            break;
        for(int i=0;i<n;i++)
        {
            if(m[i]!=0)
            {
                v[i].push_back(temp);
                temp++;
                sum--;
                m[i]--;
            }
        }
    }
    if(duo)
    {
        if(n!=1)
            temp++;
        while(m[maxi]!=0)
        {
            v[maxi].push_back(temp);
            temp+=2;
            m[maxi]--;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<"#"<<i+1<<endl;
        int cnt=0;
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j];
            cnt++;
            if(cnt==10&&j!=v[i].size()-1)
            {
                cout<<endl;
                cnt=0;
            }
            if(j!=v[i].size()-1&&cnt!=0&&cnt!=10)
                cout<<" ";
        }
        if(i!=n-1)
            cout<<endl;
    }
    return 0;
}
