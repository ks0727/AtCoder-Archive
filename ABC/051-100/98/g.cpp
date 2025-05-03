#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> A(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    // 累積和 S と累積 XOR X を構築
    vector<ll> S(N+1, 0), X(N+1, 0);
    for (int i = 1; i <= N; i++) {
        S[i] = S[i-1] + A[i];
        X[i] = X[i-1] ^ A[i];
    }

    ll ans = 0;
    int r = 0;
    // 左端 l を1からNまで動かす
    for (int l = 1; l <= N; l++) {
        // r を l-1 以上に保つ
        if (r < l-1) r = l-1;
        // 条件を満たす限り r を右に伸ばす
        while (r+1 <= N
            && (S[r+1] - S[l-1]) == (X[r+1] ^ X[l-1])) {
            r++;
        }
        // [l..r] のうち、すべて条件を満たす区間は (r-l+1) 個
        ans += (r - l + 1);
    }

    cout << ans << "\n";
    return 0;
}

