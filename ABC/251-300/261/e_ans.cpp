#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,c;
    cin >> n >> c;
    vector<pair<int,int> > op(n);
    rep(i,n) cin >> op[i].first >> op[i].second;

    vector<int> ans(n);
    rep(k,30){
        vector<int> func(2);
        int crr = (c>>k)&1;
        rep(i,n){
            vector<int> f(2);
            int x = (op[i].second>>k)&1;
            if(op[i].first == 1) f = {0&x,1&x};
            if(op[i].first == 2) f = {0|x,1|x};
            if(op[i].first == 3) f = {0^x,1^x};
            func = {f[func[0]],f[func[1]]};
            crr = func[crr];
            ans[i] |= crr << k;
        }
    }
    rep(i,n) cout << ans[i] << endl;
    return 0;
}