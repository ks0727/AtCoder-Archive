#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> r(n);
    rep(i,n) cin >> r[i];
    sort(r.begin(),r.end());
    vector<ll> s(n+1);
    rep(i,n) s[i+1] = r[i] + s[i];
    rep(qi,q){
        ll x;
        cin >> x;
        int need = upper_bound(s.begin(),s.end(),x) - s.begin() - 1;
        cout << need << endl;
    }
    return 0;
}