#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n-1);
    rep(i,n) cin >> a[i];
    rep(i,n-1) cin >> b[i];
    const int INF = 1001001001;
    int l = -1,r=INF;
    sort(a.begin(),a.end());
    while(r-l>1){
        int mid = (r+l)/2;
        auto f = [&](int x){
            vector<int> c = b;
            c.push_back(x);
            sort(c.begin(),c.end());
            rep(i,n){
                if(c[i] < a[i]) return false;
            }
            return true;
        };
        if(f(mid)) r = mid;
        else l = mid;
    }
    if(r == INF) cout << -1 << endl;
    else cout << r << endl;
    return 0;
}