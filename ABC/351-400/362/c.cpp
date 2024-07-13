#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> l(n),r(n);
    rep(i,n) cin >> l[i] >> r[i];
    ll plus = 0, minus = 0;
    ll now = 0;
    vector<ll> ans;
    vector<ll> ps(n),ms(n);
    rep(i,n){
        if(l[i] > 0){ //範囲が完全に正
            ans.push_back(l[i]);
            now += l[i];
            plus += r[i] - l[i];
            ps[i] = r[i] - l[i];
        }else if(r[i] < 0){ //範囲が完全に負
            ans.push_back(r[i]);
            now += r[i];
            minus += l[i] - r[i];
            ms[i] = l[i] - r[i];
        }else{ //範囲が0をまたぐ
            ans.push_back(0);
            ps[i] = r[i];
            ms[i] = l[i];
            plus += r[i];
            minus += l[i];
        }
    }
    if(now == 0 || (now > 0 && abs(minus) >= abs(now)) || (now < 0 && abs(plus) >= abs(now))){
        cout << "Yes" << endl;
        if(now == 0){
            rep(i,n) cout << ans[i] << ' '; cout << endl;
            return 0;
        }else if(now < 0){ //＋していって辻褄を合わせる
            ll diff = now;
            rep(i,n){
                if(ps[i] == 0) continue;
                if(abs(ps[i]) >= abs(diff)){ //完全相殺できる
                    ans[i] += abs(diff);
                    break;
                }else{
                    ans[i] += abs(ps[i]);
                    diff += ps[i];
                }
            }
            rep(i,n) cout << ans[i] << ' '; cout << endl;
            return 0; 
        }else{ //-していく
            ll diff = now;
            rep(i,n){
                if(ms[i] == 0) continue;
                if(abs(ms[i]) >= abs(diff)){//完全相殺できる
                    ans[i] -= abs(diff);
                    break;
                }else{
                    ans[i] -= abs(ms[i]);
                    diff -= abs(ms[i]);
                }
            }
            rep(i,n) cout << ans[i] << ' '; cout << endl;
            return 0;
        }
    }else{
        cout << "No" << endl;
        return 0;
    }
    return 0;
}