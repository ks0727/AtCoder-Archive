#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    map<int,int> mp;
    rep(i,n){
        mp[p[i]] = i;
    }
    int q;
    cin >> q;
    rep(qi,q){
        int a,b;
        cin >> a >> b;
        int ans = (mp[a]<mp[b]?a:b);
        cout << ans << endl;
    }
    return 0;
}