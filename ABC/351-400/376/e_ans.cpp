#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

void solve(){
    int n,k;
    cin >> n>> k;
    vector<pair<int,int> > ab(n);
    rep(i,n) cin >> ab[i].first;
    rep(i,n) cin >> ab[i].second;
    sort(ab.begin(),ab.end());

    long long ans = 1e18;
    long long sum = 0;
    priority_queue<int> q;
    for(auto [a,b] : ab){
        if(q.size() >= k-1){
            ans = min(ans,(sum+b)*a);
        }
        sum += b;
        q.push(b);
        if(q.size() == k){
            sum -= q.top();
            q.pop();
        } 
    }
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}