#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b(n-1);
    rep(i,n-1){
        b[i] = a[i]*a[i+1];
    }
    rep(i,n-1) cout << b[i] << ' ';
    cout << endl;
    return 0;
}