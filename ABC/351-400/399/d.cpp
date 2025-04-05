#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

void solve(){
    int n;
    cin >> n;
    int n2 = 2*n;
    vector<int> a(n2);
    vector<pair<int,int> > ps(n,make_pair(-1,-1));
    for(int i=0;i<n2;i++) cin >> a[i],a[i]--;
    int ans = 0;
    for(int i=0;i<n2;i++){
        if(ps[a[i]].first == -1) ps[a[i]].first = i;
        else ps[a[i]].second = i;
    }
    for(int i=0;i<n2-1;i++){
        //この時大きい方
        if(ps[a[i]].first != i) continue;
        if(ps[a[i+1]].first != i+1) continue;
        int x = ps[a[i]].second;
        if(x == i+1) continue; //2つが隣り合っていたらだめ
        if(a[x-1] == a[i+1] && x-1 > i+1){
            ans++;
            continue;
        }
        if(x == n2-1) continue;
        if(a[x+1] == a[i+1]){
            ans++;
            continue;
        }
    }
    cout << ans << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}