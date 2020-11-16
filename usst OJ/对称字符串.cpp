#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  string s[25];
  s[0]="A";
  for(int i=1;i<=24;i++)
  {
    s[i-1].append(1,'A'+i);
    s[i]=s[i-1]+s[i-1];
    s[i-1].pop_back();
    s[i].pop_back();
  }
  cout<<s[n-1];
}
