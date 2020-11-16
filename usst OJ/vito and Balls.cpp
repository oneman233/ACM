#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	while(cin>>num)
	{
		if(num==1)
		{
			cout<<"0"<<endl;
			continue;
		}
		if((num+1)%2==0)
		{
			cout<<"0"<<endl;
		}
		else
		{
			cout<<"1"<<endl;
		}
	}
	return 0;
}
