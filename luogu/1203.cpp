#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=-100;
    string s;
    cin>>n;
    cin>>s;
    for(int i=0;i<=n;++i)
    {
        int cnt=0;
        string tmp="";
        for(int j=i-1;j>=0;--j)
            tmp.append(1,s[j]);
        for(int j=n-1;j>=i;--j)
            tmp.append(1,s[j]);
        int l=0,r=n-1,j=0,k=n-1;
        while(tmp[l]=='w')
            l++;
        while(j<n){
            if(tmp[j]==tmp[l]||tmp[j]=='w')
                cnt++;
            else
                break;
            j++;
        }
        while(r>=j&&tmp[r]=='w')
            r--;
        while(k>=j){
            if(tmp[k]==tmp[r]||tmp[k]=='w')
                cnt++;
            else
                break;
            k--;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
/*
7
wwwbbrb
5
wwwww
*/
