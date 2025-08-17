#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

struct Node {
    mint cnt;    
    mint sum;
};

int main() {
    const int B = 60;                 
    vector<mint> pow2(B);
    pow2[0] = 1;
    for (int i = 1; i < B; ++i) pow2[i] = pow2[i - 1] * 2;
    int T;
    cin >> T;
    while (T--) {
        unsigned long long n;
        int k;
        cin >> n >> k;
        if (k == 0) {
            cout << 0 << '\n';
            continue;
        }

        vector<vector<vector<Node>>> dp(2,vector<vector<Node>>(k+1, vector<Node>(2)));

        int cur = 0, nxt = 1;
        dp[cur][0][1].cnt = 1;

        for (int pos = B - 1; pos >= 0; --pos) {
            for (int j = 0; j <= k; ++j)
                for (int t = 0; t < 2; ++t)
                    dp[nxt][j][t] = {};
            int nbit = (n >> pos) & 1;
            mint val = pow2[pos];

            for (int j = 0; j <= k; ++j) {
                for (int tight = 0; tight < 2; ++tight) {
                    mint cnt_here = dp[cur][j][tight].cnt;
                    mint sum_here = dp[cur][j][tight].sum;
                    if (cnt_here == 0) continue;
                    int ntight0 = (tight && nbit == 0) ? 1 : 0;
                    dp[nxt][j][ntight0].cnt += cnt_here;
                    dp[nxt][j][ntight0].sum += sum_here;

                    if (j+1<= k && !(tight && nbit == 0)) {
                        int ntight1 = (tight && nbit == 1) ? 1 : 0;
                        dp[nxt][j+1][ntight1].cnt += cnt_here;
                        dp[nxt][j+1][ntight1].sum += sum_here + val * cnt_here;
                    }
                }
            }
            swap(cur, nxt);
        }

        mint ans = dp[cur][k][0].sum + dp[cur][k][1].sum;
        cout << ans.val() << '\n';
    }
    return 0;
}

