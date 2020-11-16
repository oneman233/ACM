#include <bits/stdc++.h>

using namespace std;

long long int zhao(set<long long int> s,int n)
{
    set<long long int>::iterator it;
    it=s.begin();
    int shu=1;
    while(shu!=n)
    {
        it++;
        shu++;
    }
    return (*it);
}

int main()
{
    int n;
    int jishu=1;
    set<long long int> s;
    s.insert(1);
    set<long long int>::iterator it;
    it=s.begin();
    while(s.size()<6000)
    {
        s.insert(2*(*it));
        s.insert(3*(*it));
        s.insert(5*(*it));
        s.insert(7*(*it));
        it++;
    }
    while(cin>>n)
    {
        if(n==0)
            break;
        else if(n%10==1&&n!=11)
            printf("The %dst humble number is %lld.\n",n,zhao(s,n));
        else if(n%10==2&&n!=12)
            printf("The %dnd humble number is %lld.\n",n,zhao(s,n));
        else if(n%10==3&&n!=13)
            printf("The %drd humble number is %lld.\n",n,zhao(s,n));
        else
            printf("The %dth humble number is %lld.\n",n,zhao(s,n));
    }
    return 0;
}
