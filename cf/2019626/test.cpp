#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
string s, c;

int main(){
    cin >> n >> k >> s;
    set<string> res;
    queue<string> q;
    q.push(s);
    res.insert(s);
    ll ans = 0;
    while (!q.empty() && k > 1){
        string tmp = q.front();
        q.pop();
        if (tmp.size() == 0) break;
        for (int i = 0; i < tmp.size(); i++){
            c = tmp;
            c.erase(i, 1);
            if (res.count(c) == 0){
                q.push(c);
                res.insert(c);
                if (res.size() == k) break;
            }
        }
        if (res.size() >= k) break;
    }
    if (res.size() < k) cout << -1;
    else{
        ll cnt = 0;
        for (string u : res){
            cnt++;
            ans += n - u.size();
            if (cnt == k) break;
        }
        cout << ans;
    }
    return 0;
}
