#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int r = 1e9,l=-1;
    while(r-l>1){
        int mid = (r+l)/2;
        auto f = [&](int x){
            if(x*2 > n) return false;
            rep(i,x){
                if(n-x+i >= n) return false;
                if(a[i]*2 > a[n-x+i]) return false;
            }
            return true;
        };
        if(f(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}