#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n; ll a,b;
    cin >> n >> a >> b;
    vector<ll> d(n);
    rep(i,n) cin >> d[i],d[i]--, d[i]%=(a+b);
    sort(d.begin(),d.end());
    vector<ll> nd(n*2); 
    bool ans = false;
    rep(i,2*n){
        if(i < n) nd[i] = d[i];
        else{
            nd[i] = d[i-n]+a+b;
        }
    }
    rep(i,2*n-1){
        if(nd[i+1] - nd[i] > b){
            ans = true;
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}