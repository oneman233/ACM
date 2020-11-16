#include <bits/stdc++.h>
using namespace std;

double s,a,b;
///take the car once for each person
int main()
{
    cin>>s>>a>>b;
    double t0=s/(a*(b-a)/(b+a)+a+b);
    printf("%.6lf",2*t0+t0*(b-a)/(b+a));
    return 0;
}
