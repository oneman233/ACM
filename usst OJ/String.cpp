#include <bits/stdc++.h>
using namespace std;

int main()
{
     string s;
     long long ans=0;
     int i;
     cin>>s;
     int k;
     cin>>k;
     int maxn=0;
  map<char,int> num;
     for(char j='a';j<='z';j++)
     {
       cin>>num[j];
       if(num[j]>maxn)
         maxn=num[j];
     }
  for(i=1;i<=s.length();i++){
     ans+=num[s[i-1]]*i;
  }
  while(k--){
    ans+=i*maxn;
    i++;
  }
  cout<<ans;
     return 0;
}
