#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m,l;
    cin >> n >> m >> l;
    vector<int> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    vector<unordered_set<int> > st(n);
    rep(i,l){
        int c,d;
        cin >> c >> d;
        c--; d--;
        st[c].insert(d);
    }
    vector<int> bi(m);
    rep(i,m) bi[i] = i;
    sort(bi.begin(),bi.end(),[&](int i, int j){
        return b[i] > b[j];
    });
    int ans = 0;
    rep(i,n){
        for(int j : bi){
            if(st[i].count(j)) continue;
            ans = max(ans,a[i]+b[j]);
            break;
        }
    }
    cout << ans << endl;
}