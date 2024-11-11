#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int> > ps(m);
    long long sum = 0;
    rep(i,m) cin >> ps[i].first,ps[i].first--;
    rep(i,m){
        cin >> ps[i].second;
        sum += ps[i].second;
    }
    if(sum != n){
        cout << -1 << endl;
        return 0;
    }
    sort(ps.begin(),ps.end());
    int now = 0;
    int prev = -1;
    long long ans = 0;
    rep(i,m){
        int need = ps[i].first-prev;
        ans += (long long)need*(need+1)/2;
        now += ps[i].second;
        now -= need;
        prev = ps[i].first+1;
        //cout << now << endl;
        if(now < 0){
            cout << -1 << endl;
            return 0;
        }
    }
    if(now == n-1-prev){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}