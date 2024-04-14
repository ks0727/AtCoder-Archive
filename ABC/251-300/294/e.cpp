#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,ll>;

int main(){
    ll L; int n1,n2;
    cin >> L >> n1 >> n2;
    vector<P> p1,p2;
    rep(i,n1){
        int v; ll l;
        cin >> v >> l;
        p1.emplace_back(v,l);
    }
    rep(i,n2){
        int v; ll l;
        cin >> v >> l;
        p2.emplace_back(v,l);
    }
    const ll INF = 1e15;
    p1.emplace_back(INF,INF);
    p2.emplace_back(-INF,INF);
    ll la=0,lb=0;
    int aidx=0,bidx=0;
    ll ans = 0;
    while(aidx<n1 && bidx < n2){
        ll na = la+p1[aidx].second;
        ll nb = lb+p2[bidx].second;
        if(p1[aidx].first == p2[bidx].first){
            ans += min(na,nb) - max(la,lb);
        }
        if(na < nb){
            la = na;
            aidx++;
        }else{
            lb = nb;
            bidx++;
        }
    }
    cout << ans << endl;
    return 0;
}