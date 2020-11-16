#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num,n;
    set<int> rail;
    cin>>n;
    while(n--)
    {
        cin>>num;
        if(rail.lower_bound(num)!=rail.end())
            rail.erase(rail.lower_bound(num));
        rail.insert(num);
    }
    cout<<rail.size();
    return 0;
}
