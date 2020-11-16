#include <bits/stdc++.h>

using namespace std;

int main()
{
 int n,num;
 long sum1=0,sum2=0;
 cin>>n;
 for(int i =0;i<n;i++)
 {
 cin>>num;
 if(num>=0)
 sum1+=num;
 else
 sum2+=num;
 }
 cout<<sum1-sum2;
 return 0;
}
