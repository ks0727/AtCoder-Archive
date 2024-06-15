#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = (ll)n*(n-1)/2;
    rep(i,n) if(s[i] == '1') ans++;
    rep(i,n-1){
        int cnt = 1;
        while(i < n-1 && s[i] == '1' && s[i+1] == '1'){
            cnt++;
            i++;
        }
        ans -= (ll)cnt*(cnt-1)/2;
        cnt = 1;
    }
    cout << ans << endl;
    rep(i,n-1){
        if(s[i] == '0' && s[i+1] == '1'){
            ans -= i;
        }
    }
    cout << ans << endl;
    return 0;
}