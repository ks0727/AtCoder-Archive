#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    vector<int> a(9),b(8);
    rep(i,9) cin >> a[i];
    rep(i,8) cin >> b[i];
    int sumA = 0, sumB = 0;
    rep(i,9) sumA += a[i];
    rep(i,8) sumB += b[i];
    int ans = sumA - sumB + 1;
    cout << ans << endl;
    return 0;
}