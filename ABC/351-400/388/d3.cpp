#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int s = 0;
    vector<int> r(n);
    rep(i,n){
        a[i] += s;
        int num = min(a[i],n-i-1);
        a[i] -= num;
        s++;
        r[i+num]++;
        s -= r[i];
    }
    rep(i,n) cout << a[i] << ' '; cout << endl;
    return 0;
}