#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    ll w;
    cin >> w;
    if(w == 1){
        cout << 1 << endl;
        return 0;
    }
    ll x = 1;
    vector<ll> ans = {1,2};
    while(true){
        if(ans.back() > w) break;
        ll add = ans[ans.size()-1] + ans[ans.size()-2];
        ans.push_back(add);
    }
    ans.pop_back();
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    rep(i,ans.size()) cout << ans[i] << ' '; cout << endl;
    return 0;
}