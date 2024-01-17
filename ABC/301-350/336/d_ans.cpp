#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    a.push_back(0);
    a.insert(a.begin(),0);
    n+=2;
    vector<int> dl(n),dr(n);
    for(int i=1;i<n;i++){
        dl[i] = min(dl[i-1]+1,a[i]);
    }
    for(int i=n-2;i>=2;i--){
        dr[i] = min(dr[i-1]+1,a[i]);
    }
    int ans = 0;
    rep(i,n){
        int now = min(dl[i],dr[i]);
        ans = max(ans,now);
    }
    cout << ans << endl;
    return 0;
}