#include <bits/stdc++.h>
using namespace std;

int main(){
	int num[10];
	for(int i=0;i<9;++i) num[i]=i;
	do{
		for(int i=0;i<9;++i)
			cout<<num[i]<<' ';
		cout<<endl;
	}while(next_permutation(num,num+9));
	return 0;
}
