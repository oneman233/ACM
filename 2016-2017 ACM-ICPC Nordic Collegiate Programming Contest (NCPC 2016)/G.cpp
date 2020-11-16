#include <bits/stdc++.h>
using namespace std;

string s;

int get(int rk){
	if(rk<=25&&rk>=21) return 2;
	else if(rk<=20&&rk>=16) return 3;
	else if(rk<=15&&rk>=11) return 4;
	else if(rk<=10&&rk>=1) return 5;
}

int main()
{
	cin>>s;
	int rk=25,star=0;
	int con=0;
	for(int i=0;i<s.length();++i){
		if(s[i]=='W'){
			star++;
			con++;
			if(rk<=25&&rk>=6&&con>=3) star++;
			if(star>get(rk)){
				star-=get(rk);
				rk--;
			}
		}
		else if(s[i]=='L'){
			con=0;
			if(rk<=20&&rk>=1){
				star--;
				if(star==-1){
					if(rk!=20){
						rk++;
						star=get(rk)-1;
					}
					else star=0;
				}
			}
		}
		if(rk==0) break;
	}
	if(rk==0) cout<<"Legend";
	else cout<<rk;
	return 0;
}
//WWWWWWWWWLLWW
//WWWWWWWWWLWWL
