#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
    int n;
    cin >> n;
    vector<int> a(n-1);
    rep(i,n-1) cin >> a[i];
    int s = 0;
    rep(i,n-1) s += a[i];
    cout << -s << endl;
    return 0;
}




