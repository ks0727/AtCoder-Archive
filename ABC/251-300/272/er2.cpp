#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(n+1);
    rep(i,n) cin >> a[i+1];
    vector<vector<ll> > data(m+1);
    for(int i=1;i<=(n);i++){
        int l = 0;
        if(a[i] > 0) l = 0;
        else l = -(a[i]-i+1)/i;
        int r = (n-a[i])/i;
        for(int j = l;j <= r;j++){
            if(j >= m+1) break;
            ll add = a[i]+i*j;
            if(add > n) break;
            data[j].push_back(add);
        }
    }
    rep(i,m+1){
        sort(data[i].begin(),data[i].end());
        data[i].erase(unique(data[i].begin(),data[i].end()),data[i].end());
    }
    for(int i=1;i<=m;i++){
        if(data[i].size() == 0){
            cout << 0 << endl;
            continue;
        }
        int cnt = 0;
        bool ok = false;
        rep(j,data[i].size()){
            if(data[i][j] != cnt){
                cout << cnt << endl;
                ok = true;
                break;
            }else cnt++;
        }
        if(!ok) cout << cnt << endl;
    }
    return 0;
}