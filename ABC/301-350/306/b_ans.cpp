#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ull = unsigned long long;

int main(){
    ull ans = 0;
    rep(i,64){
        ull a;
        cin >> a;
        ans += a << i;
    }
    cout << ans << endl;
}