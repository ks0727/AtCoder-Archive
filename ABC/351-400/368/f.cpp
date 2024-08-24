#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    if(n%2 == 1){
        cout << "Anna" << endl;
        return 0;
    }
    auto f = [&](int x){
        int res = 0;
        for(int p =2;p*p<=x;p++){
            if(x%p != 0) continue;
            while(x%p==0){
                x /= p;
                res++;
            }
        }
        if(x != 1) res++;
        return res;
    };
    ll k = 0;
    rep(i,n) k += f(a[i]);
    rep(i,n) cout << f(a[i]) << ' '; cout << endl;
    if(k % 2 == 0) cout << "Bruno" << endl;
    else cout << "Anna" << endl;
    return 0;
}