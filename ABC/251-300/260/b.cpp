#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
int main(){
    int n,x,y,z;
    cin >> n >> x >> y >> z;
    vector<P> a(n),b(n),s(n);
    rep(i,n) cin >> a[i].first;
    rep(i,n) cin >> b[i].first;
    rep(i,n) s[i].first = a[i].first + b[i].first;
    rep(i,n){
        a[i].second = b[i].second = s[i].second = -i;
    }
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    sort(s.rbegin(),s.rend());
    vector<bool> passed(n);
    rep(i,x){
        passed[-a[i].second] = true;
    }
    int y_cnt = 0;
    rep(i,n){
        if(y_cnt == y) break;
        if(!passed[-b[i].second]){
            passed[-b[i].second] = true;
            y_cnt++;
        }
    }
    int z_cnt = 0;
    rep(i,n){
        if(z_cnt == z) break;
        if(!passed[-s[i].second]){
            passed[-s[i].second] = true;
            z_cnt++;
        }
    }
    rep(i,n){
        if(passed[i]) cout << i+1 << endl;
    }
    return 0;
}