#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    FILE *fp = fopen("ou.txt","w");
    srand(time(NULL));
    fprintf(fp,"1");
    for(int i =0; i< 199999;i++){
        fprintf(fp,"%d",(rand())%2);
    }
    fclose(fp);
    return 0;
}
