#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m,p;
    cin >> n >> m >> p;
    vector<int> a(n);
    vector<int> b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans = 0;
    rep(i,m){
        rep(j,n){
            int set = b[i] + a[j];
            if(set > p){
                ans += p;
                ans += p*(n-1-j);
                break;
            }
            else  ans += set;
        }
    }
    cout << ans << endl;
    return 0;
}