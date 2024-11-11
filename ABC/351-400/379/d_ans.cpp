#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int Q;
    cin >> Q;
    queue<ll> q;
    ll now = 0;
    rep(qi,Q){
        int type;
        cin >> type;
        if(type == 1){
            q.push(now);
        }
        else if(type == 2){
            ll t;
            cin >> t;
            now += t;
        }
        else if(type == 3){
            ll h;
            cin >> h;
            int ans = 0;
            while(!q.empty() && now-q.front() >= h){
                ans++;
                q.pop();
            }
            cout << ans << '\n';
        }
    }
    return 0;
}