#include <bits/stdc++.h>
using namespace std;

char s[1000005];
int ans[140005];
stack<int>stk;

int main(){
	int n; scanf("%d",&n);
	scanf("%s",s);
	int len=strlen(s);
	int num=0;
	for(int i=0; i<len; ++i){
		if(isdigit(s[i])){
			num*=10, num+=s[i]-'0';
			continue;
		}
		else if(num==0){
			if(s[i]==')') stk.pop();
		}else{	//num!=0
			if(stk.size()) ans[num]=stk.top();
			if(s[i]=='(') stk.push(num);
//			else if(s[i]==')')
			num=0;
		}
//		else if(s[i]=='('){
//			if(stk.size()) ans[num]=stk.top();
//			stk.push(num);
//			num=0;
//		}
//		else if(s[i]==')'){
//			if(num && stk.size()) ans[num]=stk.top();
//			else stk.pop();
//			num=0;
//		}
	}
	for(int i=1; i<=n; ++i) printf("%d ",ans[i]);
	return 0;
}
