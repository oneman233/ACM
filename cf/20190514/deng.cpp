#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(0));
    FILE *fp=fopen("out.txt","w");
    for(int i=0;i<200000;++i)
    {
        fprintf(fp,"%c",'a'+rand()*100%26);
    }
    fclose(fp);
    return 0;
}
