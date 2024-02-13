#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    vector<int> a(n);
    rep(i,n){
        int diff = p[i] - i;
        auto f = [&](int d)->void{
            int now = d-1;
            rep(j,3){
                a[(now+n)%n]++;
                now++;
            }
        };
        f(diff);
    }
    int ans = -1;
    rep(i,n) ans = max(ans,a[i]);
    cout << ans << endl;
    return 0;
}