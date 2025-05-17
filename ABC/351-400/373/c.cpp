#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    cout << a[0]+b[0] << endl;
    return 0;
}
