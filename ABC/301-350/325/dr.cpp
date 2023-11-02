#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,ll>;

int main(){
    int n;
    cin >> n;
    queue<P> unused;
    priority_queue<ll,vector<ll>,greater<ll>> canuse;
    vector<P> arr(n);
    const ll MX = 2e18; 
    rep(i,n){
        ll t,d;
        cin >> t >> d;
        arr[i].first = t;
        arr[i].second = t+d;
    }
    sort(arr.begin(),arr.end());
    rep(i,n){
        unused.push(arr[i]);
    }
    int ans = 0;
    ll t = arr[0].first;
    while(t < MX+1 && t <= arr[n-1].second){
        while(t == unused.front().first){
            canuse.push(unused.front().second);
            unused.pop();
        }
        canuse.pop();
        ans++;
        t++;
        if(canuse.empty()){
            t = unused.front().first;
        }else{
            while(t > canuse.top()){
                canuse.pop();
            }
        }
    }
    cout << ans << endl;
    return 0;
}