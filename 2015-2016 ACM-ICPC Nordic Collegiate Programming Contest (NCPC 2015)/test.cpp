#include <bits/stdc++.h>
using namespace std;

multiset<int> s;

int main()
{
	s.insert(1);
	s.insert(3);
	s.insert(5);
	auto it=s.lower_bound(9);
	printf("%d\n",it==s.end());
	printf("%d",*it); 
	return 0;
}
