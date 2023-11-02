#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,ll>;

int main(){
    int n;
    cin >> n;
    vector<P> a(n);
    ll mx = 0;
    rep(i,n){
        ll t,d;
        cin >> t >> d;
        a[i].first = t;
        a[i].second = t + d;
        mx = max(mx,a[i].second);
    }
    sort(a.begin(),a.end());
    ll t = a[0].first;
    int ans = 0;
    int ai = 0;
    priority_queue<ll,vector<ll>,greater<ll> > q;
    while(!q.empty() || ai < n){
        while(a[ai].first <= t && ai < n){
            q.push(a[ai].second);
            ai++;
        }
        while(q.top() < t && !q.empty()){
            q.pop();
        }
        if(!q.empty()){
            q.pop();
            ans++;
        }
        if(q.empty() && ai < n){
            t = a[ai].first;
        }else t++;
    }
    cout << ans << endl;
    return 0;
}