#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> q(n),a(n),b(n);
    rep(i,n) cin >> q[i];
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    const int INF = 1001001001;
    int mxa = INF;
    rep(i,n){
        if(a[i] != 0) mxa = min(mxa,q[i]/a[i]);
    }
    int ans = -1;
    rep(i,mxa+1){
        vector<int> nq = q;
        rep(j,n){
            nq[j] -= a[j]*i;
        }
        int now = INF;
        rep(j,n){
            if(b[j] != 0) now = min(now,nq[j]/b[j]);
        }
        ans = max(ans,now+i);
    }
    cout << ans << endl;
    return 0;
}