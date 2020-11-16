#include <bits/stdc++.h>

using namespace std;

int main()
{
	map<string,int> a;
	set<string> b;
	int n;
	int max=-1;
	cin>>n;
	string temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		a[temp]++;
		b.insert(temp);
	}
	map<string,int>::iterator it;
	for(it=a.begin();it!=a.end();it++)
	{
		if(it->second>max)
			max=it->second;
	}
	cout<<b.size()<<endl;
	set<string>::iterator itt;
	while(max!=0)
	{
		for(it=a.begin();it!=a.end();it++)//检查颜色对应次数
		{
			if(it->second==max)
			{
				cout<<max<<endl;
				for(itt=b.begin();itt!=b.end();itt++)
				{
					if(a[*itt]==max)
					{
						cout<<*itt;
						n-=max;
						if(n!=0)
							cout<<"\n";
					}
				}
				break;
			}
		}
		max--;
	}
	return 0;
}
