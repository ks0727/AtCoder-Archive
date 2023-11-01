#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    const ll INF = 1e18;
    ll ans = INF;
    string t = s;
    rep(i,n){
        ll temp = 0;
        temp += (ll)a*i;
        rep(j,n) s[j] = t[(j+i)%n];
        for(int j=0;j*2<(n);j++){
            if(s[j] != s[n-j-1]) temp += (ll)b;
        }
        ans = min(ans,temp);
    }
    cout << ans << endl;
    return 0;
}