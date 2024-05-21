#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    vector<int> is(n);
    rep(i,n) is[i] = i+1;
    sort(a.begin(),a.end());
    if(a[0] == 1 || a[m-1] == n){
        cout << -1 << endl;
        return 0;
    }
    rep(i,m) swap(is[a[i]-1],is[a[i]]);
    rep(i,n) cout << is[i] << ' '; cout << endl;
    return 0;
}