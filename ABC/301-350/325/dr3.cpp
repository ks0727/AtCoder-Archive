#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,ll>;

int main(){
    int n;
    cin >> n;
    vector<P> a(n);
    rep(i,n){
        ll t,d;
        cin >>  t >> d;
        a[i].first = t;
        a[i].second = t+d;
    }
    sort(a.begin(),a.end());
    priority_queue<ll,vector<ll>,greater<ll> > q;
    int ans = 0;
    int ai = 0;
    ll t = 0;
    while(!q.empty() || ai < n){
        while(ai < n && t == a[ai].first){
            q.push(a[ai].second);
            ai++;
        }
        if(!q.empty()){
            q.pop();
            ans++;
        }
        if(q.empty()){
            t = a[ai].first;
        }else t++;
        while(!q.empty() && q.top() < t){
            q.pop();
        }
    }
    cout << ans << endl;
}