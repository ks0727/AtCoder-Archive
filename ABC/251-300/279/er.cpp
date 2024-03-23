#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    vector<int> oidx(m);
    int now = 1;
    rep(i,m){
        if(now == a[i]){
            now = now+1;
        }else if(now == a[i]+1){
            now = now-1;
        }
        oidx[i] = now;
    }
    vector<int> ans;
    //rep(i,m) cout << oidx[i] << ' '; cout << endl;
    reverse(oidx.begin(),oidx.end());
    reverse(a.begin(),a.end());
    vector<int> b(n);
    rep(i,n) b[i] = i+1;
    rep(i,m){
        swap(b[a[i]-1],b[a[i]]);
        ans.push_back(b[oidx[i]-1]);
    }
    for(int i=m-1;i>=0;i--){
        cout << ans[i] << '\n';
    }
    return 0;
}