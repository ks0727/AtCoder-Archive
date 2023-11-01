#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    long long a;
    long long b;
    cin >> a;
    const auto &pf = prime_factorize(a);
    long long res = 1;
    for (auto p : pf) res *= p.second + 1;
    cout << res << endl;
    cout << 335*168*168*168 << endl;
}
