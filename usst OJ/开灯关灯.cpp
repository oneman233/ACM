#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,t;
	cin>>n>>t;
	int deng[55];
	int deng2[55];
	for(int i=0;i<n;i++)
		cin>>deng[i];
	while(t--)
	{
		for(int i=1;i<n-1;i++)
		{
			if(deng[i-1]^deng[i+1])
				deng2[i]=1-deng[i];
			else
			{
				deng2[i]=deng[i];
			}
		}
		if(deng[1])
			deng2[0]=1-deng[0];
		else
			deng2[0]=deng[0];
		if(deng[n-2])
			deng2[n-1]=1-deng[n-1];
		else
			deng2[n-1]=deng[n-1];
		for(int i=0;i<n;i++)
			deng[i]=deng2[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<deng[i];
		if(i!=n)
			cout<<" ";
	}
	return 0;
}
