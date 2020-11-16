#include <bits/stdc++.h>
using namespace std;

double num[4005];

int main()
{
	freopen("in.txt","r",stdin);
	for(int i=1;i<=4000;++i)
		cin>>num[i];
	for(int i=1;i<=4000;++i)
		cout<<num[i]<<endl;
	return 0;
}
