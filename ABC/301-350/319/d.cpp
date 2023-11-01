#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i =0;i<(n);i++)
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> l(n);
    rep(i,n) cin >> l[i];
    ll w = 0;
    int cnt = 0;
    bool possible = false;
    while(true){
        w += l[cnt];
        if(cnt != 0) w++;
        ll length = 0;
        ll used_wid = 0;
        rep(i,n){
            if(length != 0) length +=1;
            length += l[i];
            if(length > w){
                length = l[i];
                used_wid++;
            }
            if(used_wid > m) break;
            if(m == 1){
                if(used_wid+1 > m) break;
            }
            if(i == n-1) possible = true;
        }
        if(possible) break;
        cnt++;
    }
    cout << w << endl;
    return 0;
}