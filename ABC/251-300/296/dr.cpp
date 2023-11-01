#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=1;i<(n);i++)
using ll = long long;

int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> candidate;
    rep(i,n+1){
        candidate.push_back((m-1+i)/i);
        if(i*i > m) break;
    }
    ll const INF = 1e18;
    ll ans = INF;
    int size = candidate.size();
    for(int i=1;i<(n+1);i++){
        if(i-1 <= size){
            if(candidate[i-1] >= (i) && candidate[i-1]*(i) >= m && candidate[i-1] <= n){
            ans = min(ans,candidate[i-1]*(i));
            }
        }
        else break;
    }
    if(ans == INF) cout << -1 << endl;
    else cout <<  ans << endl;
}