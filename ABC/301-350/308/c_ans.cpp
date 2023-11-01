#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,n) b[i] += a[i];
    vector<int> ans(n);
    rep(i,n) ans[i] = i;
    stable_sort(ans.begin(),ans.end(),[&](int i,int j){
        return (ll)a[i]*b[j] > (ll)a[j]*b[i];
    });
    rep(i,n) cout << ans[i+1] << ' ';
    cout << endl;
    return 0;
}