#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> maxL(m+1,-1);
    rep(i,n){
        int l,r;
        cin >> l >> r;
        maxL[r] = max(maxL[r],l);
    }
    ll ans = 0;
    int l = 1;
    for(int r=1;r<=m;r++){
        while(l <= maxL[r]) l++;//その場所の最大の左端よりも
        ans += r-l+1;
    }
    cout << ans << endl;
    return 0;
}