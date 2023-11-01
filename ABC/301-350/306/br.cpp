#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ull = unsigned long long;

int main(){
    vector<int> a(64);
    ull ans = 0;
    rep(i,64) cin >> a[i];
    for(int i = 63;i >=0;i--){
        ans = ans * 2 + a[i]; 
    }
    cout << ans << endl;
}