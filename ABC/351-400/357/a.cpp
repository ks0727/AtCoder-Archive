#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int ans = 0;
    rep(i,n){
        m -= h[i];
        if(m < 0) break;
        ans++;
    }
    cout << ans << endl;
    return 0; 
}