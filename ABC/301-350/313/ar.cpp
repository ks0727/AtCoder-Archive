#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    int mx = -1;
    rep(i,n) mx = max(mx,p[i]);
    int ans = 0;
    if(p[0] != mx) ans = mx + 1 - p[0];
    if(p[0] == mx){
        if(find(p.begin()+1,p.end(),p[0]) == p.end()) ans = 0;
        else ans = 1;
    }
    cout << ans << endl;
    return 0;
}