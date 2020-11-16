#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int Max=500000;

int t;
string s;
set<int> run;

int main()
{
    run.insert(2000);
    run.insert(2004);
    run.insert(2008);
    run.insert(2012);
    run.insert(2016);
    run.insert(2020);
    run.insert(2024);
    run.insert(2028);
    run.insert(2032);
    run.insert(2036);
    run.insert(2040);
    run.insert(2044);
    run.insert(2048);
    run.insert(2052);
    run.insert(2056);
    run.insert(2060);
    run.insert(2064);
    cin>>t;
    getchar();
    while(t--)
    {
        getline(cin,s);
        string days="",years="",months="";
        _rep(i,0,3)
            years.append(1,s[i]);
        _rep(i,4,5)
            months.append(1,s[i]);
        _rep(i,6,7)
            days.append(1,s[i]);
        int day,year,month;
        stringstream ss,ssss,sssss;
        ss<<days;
        ss>>day;
        ssss<<months;
        ssss>>month;
        sssss<<years;
        sssss>>year;
        int xingqi=s[9]-'0';
        string ns="";
        int n;
        _rep(i,11,s.length())
            ns.append(1,s[i]);
        stringstream sss;
        sss<<ns;
        sss>>n;
        xingqi+=(n%7);
        if(xingqi>7)
            xingqi-=7;
        ///cout<<year<<" "<<month<<" "<<day<<" "<<xingqi<<" "<<n<<endl;
        while(n--)
        {
            day++;
            if(day==31&&(month==4||month==6||month==9||month==11))
            {
                day=1;
                month++;
            }
            if(day==32&&(month==1||month==3||month==5||month==7||month==8||month==10||month==12))
            {
                day=1;
                month++;
            }
            if(day==30&&month==2&&run.count(year))
            {
                day=1;
                month++;
            }
            if(day==29&&month==2&&!run.count(year))
            {
                day=1;
                month++;
            }
            if(month==13)
            {
                month=1;
                year++;
            }
            ///cout<<year<<" "<<month<<" "<<day<<endl;
        }
        ///cout<<year<<" "<<month<<" "<<day<<endl;
        printf("%d%02d%02d %d\n",year,month,day,xingqi);
    }
}
