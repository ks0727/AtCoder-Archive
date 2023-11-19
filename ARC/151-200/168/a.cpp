#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    ll ans = 0;
    rep(i,n-1){
        while(s[i] == '>'){
            cnt++;
            i++;
        }
        ans += (ll)cnt*(cnt+1)/2;
        cnt = 0;
    }
    cout << ans << endl;
    return 0;
}