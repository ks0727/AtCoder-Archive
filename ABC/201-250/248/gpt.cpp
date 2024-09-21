#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using P = pair<ll,ll>;

int main(){
    int n, k;
    cin >> n >> k;
    vector<P> ps(n);
    rep(i, n) cin >> ps[i].first >> ps[i].second;

    if(k == 1){
        // 無数の直線は存在しないため、Infinity の出力は不要です。
        cout << "Infinity" << endl;
        return 0;
    }

    const ll INF = 3e18;
    
    // 斜率を計算し、約分する関数
    auto f = [&](ll num, ll den) {
        if(den < 0) {
            den *= -1;
            num *= -1;
        } else if(den == 0) {
            return P(INF, 0); // x座標が同じ場合
        }
        ll g = gcd(num, den);
        return P(num / g, den / g);
    };

    // 2点間の直線の傾きを返す関数
    auto grad = [&](P p1, P p2) {
        ll num = p2.second - p1.second;
        ll den = p2.first - p1.first;
        auto [c, d] = f(num, den);
        return P(c, d);
    };

    // 2点から直線のy切片を返す関数
    auto inc = [&](P p1, P p2) {
        ll num = p1.first * p2.second - p2.first * p1.second;
        ll den = p2.first - p1.first;
        auto [c, d] = f(num, den);
        return P(c, d);
    }; 

    // 傾きとy切片をペアにして直線をカウント
    map<pair<P,P>, set<int>> mp;
    
    rep(i, n) {
        for(int j = i + 1; j < n; j++) {
            auto [a, b] = grad(ps[i], ps[j]);
            auto [c, d] = inc(ps[i], ps[j]);
            mp[make_pair(P(a,b),P(c,d))].insert(i);
            mp[make_pair(P(a,b),P(c,d))].insert(j);
        }
    }

    ll ans = 0;

    // K個以上の点を通る直線をカウント
    for(auto &[p, points] : mp) {
        if(points.size() >= k) ans++;
    }

    cout << ans << endl;

    return 0;
}
