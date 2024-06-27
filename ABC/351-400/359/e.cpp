#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    stack<P> s;
    vector<ll> ans;
    ll now = 0;
    s.push(P(0,0));
    rep(i,n){
        int nh = h[i];
        int d = 1;
        while (!s.empty()){
            auto [oh,od] = s.top();
            if(oh < nh){
                now -= (ll)od*oh;
                d += od;
                s.pop();
            }else break;
        }
        s.push(P(nh,d));
        now += (ll)nh*d;
        ans.push_back(now);
    }
    for(ll x : ans) cout << x+1 << ' '; cout << endl;
    return 0;
}