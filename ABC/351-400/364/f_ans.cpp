#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main(){
    int n,q;
    cin >> n >> q;
    set<int> sep;
    rep(i,n-1) sep.insert(i); //i番目の要素の直後の切れ目
    vector<tuple<int,int,int> > qs;
    ll ans = 0;
    rep(qi,q){
        int l,r,c;
        cin >> l >> r >> c;
        l--; r--;
        qs.emplace_back(c,l,r);
    }
    sort(qs.begin(),qs.end());
    for(auto [c,l,r] : qs){
        ans += c;
        auto it = sep.lower_bound(l);
        while(it != sep.end() && *it < r){
            sep.erase(it++);
            ans += c;
        }
    }
    if(sep.size() == 0) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}