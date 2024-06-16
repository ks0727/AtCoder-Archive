#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    multiset<int> a;
    vector<int> b(m);
    rep(i,n){
        int x;
        cin >> x;
        a.insert(x);
    } 
    rep(i,m) cin >> b[i];
    const int INF = 1001001001;
    a.insert(INF);
    sort(b.begin(),b.end());
    ll ans = 0;
    rep(i,m){
        if(a.size() == 0){
            cout << -1 << endl;
            return 0;
        }
        auto s = a.lower_bound(b[i]);
        if(*s == INF){
            cout << -1 << endl;
            return 0;
        }
        a.erase(s);
        ans += *s;
    }
    cout << ans << endl;
    return 0;
}