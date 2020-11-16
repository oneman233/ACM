#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	long n;
	while(~scanf("%ld",&n)){
		int a[n];
		int temp;
		for(long i = 0;i<n;i++){
			scanf("%d",&a[i]);
			//printf("%c",temp^'B');
		}
		for(char i = 'A'; i<='Z';i++){
			int j;
			for(j = 0 ;j<n;j++){
				if((a[j]^i) > 'Z' || (a[j]^i) < 'A'){
					//printf("%c",a[j]^i);
					break;
				}
			}
			if(j == n){
				for(int k = 0; k<n;k++){
					printf("%c",a[k]^i);
				}
				break;
			}
		}
		printf("\n");
	}
	return 0;
}
