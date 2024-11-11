#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,k;
    cin >> n>> k;
    string s;
    cin >> s;
    int ans = 0;
    vector<bool> seen(n);
    rep(i,n){
        if(seen[i]) continue;
        rep(j,k){
            if(i+j >= n) break;
            if(s[i+j] == 'X') break;
            if(j == k-1){
                rep(l,k){
                    seen[i+l] = true;
                }
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}