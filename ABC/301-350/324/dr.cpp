#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    s.resize(13,'0');
    sort(s.begin(),s.end());
    int ans = 0;
    ll mx = 1;
    rep(i,n){
        mx *= 10;
    }
    for(int i=0;(ll)i*i<mx;i++){
        ll value = (ll)i*i;
        string t = to_string(value);
        t.resize(13,'0');
        sort(t.begin(),t.end());
        if(t == s) ans++;
    }
    cout << ans << endl;
}