#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<bool> used(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    rep(i,n){
        if(used[i]) continue;
        auto it = lower_bound(a.begin(),a.end(),a[i]*2);
        if(it == a.end()) continue;
        if(*it == a[i]*2){
            used[i] = true;
            used[it-a.begin()] = true;
            ans++;
        }
    }
    rep(i,n){
        if(used[i]) continue;
        auto it = upper_bound(a.begin(),a.end(),a[i]*2);
        if(it == a.end()) continue;
        if(!used[it-a.begin()]){
            ans++;
            used[i] = true;
        }
    }
    cout << ans << endl;
    return 0;
}