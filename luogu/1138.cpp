#include <bits/stdc++.h>
using namespace std;

int n,k,tmp;
set<int> s;

int main()
{
    cin>>n>>k;
    while(n--){
        cin>>tmp;
        s.insert(tmp);
    }
    if(s.size()<k){
        cout<<"NO RESULT";
    }
    else{
        auto it=s.begin();
        while(--k)
            it++;
        cout<<*it;
    }
    return 0;
}
