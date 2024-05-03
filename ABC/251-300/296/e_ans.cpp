#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) a[i]--;
    vector<bool> used(n);
    vector<int> ord(n);
    int ans = 0;
    rep(sv,n){
        int k = 1;
        int v = sv;
        if(used[v]) continue;
        while(1){ //訪れた順番に印をつけていく
            if(used[v]) break;
            if(ord[v] != 0){
                ans += k - ord[v];
                break;
            }
            ord[v] = k; k++;
            v = a[v];
        }
        v = sv;
        while(!used[v]){ //すでに訪れたかどうかを判定
            used[v] = true;
            v = a[v];
        }
    }   
    cout << ans << endl;
    return 0;
}