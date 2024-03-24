#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<ll> f0(n + 1), f1(n + 1), g0(n + 1), g1(n + 1);
    for (int i = 0; i < n; i++) {
        f0[i + 1] = f0[i];
        f1[i + 1] = f1[i];
        if (i % 2 == 0) {
            if (s[i] == '0') f1[i + 1] += c[i];
            else f0[i + 1] += c[i];
        }
        else {
            if (s[i] == '0') f0[i + 1] += c[i];
            else f1[i + 1] += c[i];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        g0[i] = g0[i + 1];
        g1[i] = g1[i + 1];
        if (i % 2 == 0) {
            if (s[i] == '0') g0[i] += c[i];
            else g1[i] += c[i];
        }
        else {
            if (s[i] == '0') g1[i] += c[i];
            else g0[i] += c[i];
        }
    }
    ll ans = 1'000'000'000'000'000'000;
    rep(i,n) cout << f0[i] << ' '; cout << endl;
    rep(i,n) cout << g0[i] << ' '; cout << endl;
    rep(i,n) cout << f1[i] << ' '; cout << endl;
    rep(i,n) cout << g1[i] << ' '; cout << endl;
    for (int i = 1; i < n; i++) ans = min(ans, f0[i] + g0[i]);
    for (int i = 1; i < n; i++) ans = min(ans, f1[i] + g1[i]);
    cout << ans << '\n';
}
