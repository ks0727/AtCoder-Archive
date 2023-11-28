#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n; ll t;
    cin >> n >> t;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> s(n+1);
    rep(i,n) s[i+1] = s[i]+(ll)a[i];
    ll d;
    if(t > s[n]){
        d = t/s[n];
        t -= d*s[n];
    }  
    int song = lower_bound(s.begin(),s.end(),t) - s.begin();
    cout << song << ' ' << t-s[song-1]<< endl;
    return 0;
}