#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        //0回の時
        rep(i,n){
            if(a[i] != i+1) break;
            if(i == n-1){
                cout << 0 << '\n';
                return;
            }
        }
        vector<int> lmax(n+1),rmin(n+1);
        rmin[n] = 1e9;
        rep(i,n) lmax[i+1] = max(lmax[i],a[i]);
        for(int i=n-1;i>=0;i--) rmin[i] = min(rmin[i+1],a[i]);
        //rep(i,n+1) cout << lmax[i] << ' '; cout << endl;
        //rep(i,n+1) cout << rmin[i] << ' '; cout << endl;
        //最初と最後が同じで1回の時
        if(a[0] == 1 || a[n-1] == n){
            cout << 1 << '\n';
            return;
        }
        //それ以外の1回の時
        bool two = false;
        for(int i=1;i<n-1;i++){
            if(a[i] == i+1 && lmax[i] < rmin[i+1]){ //i番目の数字が同じで, i番目までの最大値よりもi+1番目までの最小値が大きかったら1回で済む
                cout << 1 << '\n';
                return;
            }
            if(lmax[i] < rmin[i+1]) two = true;
            if(a[i] < lmax[i] && a[i] < rmin[i+1]) two = true;
            
        }
        if(two){
            cout << 2 << endl;
            return;
        }else{
            cout << 3 << endl;
            return;
        }
}

int main(){
    int t;
    cin >> t;
    rep(ti,t) solve();
    return 0;
}