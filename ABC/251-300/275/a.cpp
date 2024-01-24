#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int now = -1;
    int ans = -1;
    rep(i,n){
        if(now < h[i]){
            now = h[i];
            ans = i+1;
        }
    }
    cout << ans << endl;
    return 0;
}