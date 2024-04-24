#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,ll>;

int main(){
    ll il,ir;
    cin >> il >>ir;
    vector<P> ans;
    auto dfs = [&](auto dfs, P LR, P lr)->void{
        auto [L,R] = LR;
        auto [l,r] = lr;
        //cout << L << ' ' << R << ' ' << l << ' ' << r << endl;
        if(L > r || R < l) return;
        if(l == L && r == R){
            ans.push_back(lr);
            return;
        }
        ll middle = (L+R)/2;
        if(l < middle && middle < r){
            dfs(dfs,P(L,middle),P(l,middle));
            dfs(dfs,P(middle,R),P(middle,r));
        }else if(l < middle && r <= middle){
            dfs(dfs,P(L,middle),P(l,r));
        }else if(l >= middle && r > middle){
            dfs(dfs,P(middle,R),P(l,r));
        }
    };
    dfs(dfs,P(0,(ll)1<<60),P(il,ir));
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for(auto [l,r] : ans){
        cout << l << ' ' << r << endl;
    }
    return 0;
}