#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int n;
        cin>>s>>n;
        vector<char> v;
        for(int i=0;i<s.length();++i)
            v.push_back(s[i]);
        vector<char>::iterator it;
        for(int i=0;i<n;++i)
        {
            int del=-1;
            for(int j=0;j<v.size()-1;++j)
            {
                if(v[j]>v[j+1])
                {
                    del=j;
                    break;
                }
            }
            if(del==-1)
            {
                v.pop_back();
            }
            else
            {
                it=v.begin();
                for(int j=0;j<del;++j)
                    ++it;
                v.erase(it);
            }
        }
        for(int i=0;i<v.size();++i)
            cout<<v[i];
        cout<<endl;
    }
    return 0;
}
