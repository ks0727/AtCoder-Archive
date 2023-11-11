#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> s(n);
    rep(i,n) cin >> s[i];
    int ans = 0;
    rep(i,n){
        if(s[i] <= x){
            ans += s[i];
        }
    }
    cout << ans << endl;
    return 0;
}