#include <iostream>
using namespace std;
long long f(long long n)
{
    if (n < 20190001)
        return n + 2018;
    return f(f(n - 2019));
}
int main()
{
    long long n;
    cin >> n;
    if(n<20190001)
        cout << n+2018 << endl;
    else
    {

        //n-=((n-20190001)/2019+1)*2019;

        /*
        while(n>=20190001)
            n-=2019;
        */
        cout << 20192018 << endl;
    }
    return 0;
}
