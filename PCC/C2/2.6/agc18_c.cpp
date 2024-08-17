#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,k;
    cin >> n>> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int x = a[0];
    for(int i=1;i<n;++i) x = gcd(x,a[i]);
    sort(a.begin(),a.end());
    if(k <= a[n-1] && k % x == 0) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}