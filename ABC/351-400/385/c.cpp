#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    const int M = 3001;
    int ans = 0;
    for(int i=1;i<M;i++){
        vector<bool> seen(n);
        rep(j,n){
            if(seen[j]) continue;
            seen[j] = true;
            int cnt = 1;
            int c = j+i;
            while(c < n && h[c] == h[j]){
                seen[c] = true;
                c += i;
                cnt++;
            }
            ans = max(ans,cnt);
        }
    }
    cout << ans << endl;
    return 0;
}