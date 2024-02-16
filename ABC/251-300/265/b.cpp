#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,ll>;

int main(){
    int n,m; ll t;
    cin >> n >> m >> t;
    vector<ll> a(n-1);
    rep(i,n-1) cin >> a[i];
    priority_queue<P,vector<P>, greater<P> > q;
    rep(i,m){
        ll x,y;
        cin >> x >> y;
        x--;
        q.emplace(x,y);
    }
    bool ans = true;
    rep(i,n-1){
        t -= a[i];
        if(q.size() != 0 && i == q.top().first){
            t += q.top().second;
            q.pop();
        }
        if(t <= 0){
            ans = false;
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}