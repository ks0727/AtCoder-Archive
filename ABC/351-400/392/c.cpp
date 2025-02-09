#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<int> p(n),q(n),to(n);
    rep(i,n) cin >> p[i],p[i]--;
    rep(i,n){
        cin >> q[i],q[i]--;
        to[q[i]] = p[i];
    }
    rep(i,n) cout << q[to[i]] +1 << ' '; cout << endl;
    return 0;
}