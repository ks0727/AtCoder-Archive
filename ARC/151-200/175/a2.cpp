#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;i++)
using mint = modint998244353;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n){
        cin >> p[i];
        p[i]--;
    } 
    string s;
    cin >> s;
    char c = '!';
    rep(i,n){
        if(s[p[i]] != '?'){
            c = s[p[i]];
            break;
        }
    }
    auto fr = [&](string ns,bool ex = false)->mint{
        vector<bool> used(n);
        mint ans = 1;
        if(ex) used[(p[0]+1)%n] = true;
        rep(i,n){
                if(ex && i ==0 ) continue;
                if(used[p[i]] && used[(p[i]+1)%n]) return 0;
                if(used[(p[i]+1)%n]){ //右が使われていたらだめ
                    return 0;
                }else{ //右は空いている時
                    if(ns[p[i]] == 'R') used[(p[i]+1)%n] = true;
                    if(ns[p[i]] == 'L' && !used[p[i]]) return 0;
                    else if(ns[p[i]] == 'L' && used[p[i]]) used[(p[i]+1)%n] = true;
                    else if(ns[p[i]] == '?'){
                    if(!used[p[i]]) used[(p[i]+1)%n] = true;
                    else{
                        ans *= 2;
                        used[(p[i]+1)%n] = true;
                    }
                }
            }
        }
        return ans;
    };
    auto fl = [&](string ns,bool ex = false)->mint{
        vector<bool> used(n);
        mint ans = 1;
        if(ex) used[p[0]] = true;
        rep(i,n){
            if(ex && i == 0) continue;
            if(used[p[i]] && used[(p[i]+1)%n]) return 0; //両方使われていたらだめ
            if(used[p[i]]) return 0; //左が使われていたらだめ
            else{ //左が空いている時
                if(ns[p[i]] == 'L') used[p[i]] = true; //左ききは左を使う
                if(ns[p[i]] == 'R' && !used[(p[i]+1)%(n+1)]) return 0; //右ききで右が使われていなかったらだめ
                else if(ns[p[i]] == 'R' && used[(p[i]+1)%n]) used[p[i]] = true; //右ききで右が使われていたら左を使う
                if(ns[p[i]] == '?'){
                    if(!used[(p[i]+1)%n]) used[p[i]] = true; //両方空いていたら左を使う
                    else{ //右がなかったら左を使う(この場合右ききでも良い)
                        ans *= 2;
                        used[p[i]] = true;
                    }
                }
            }
        }
        return ans;
    };
    if(c == '!'){
        string sr,sl;
        sr = sl = s;
        sr[p[0]] = 'R';
        sl[p[0]] = 'L';
        mint ans = fr(sr,true) + fl(sl,true);
        cout << ans.val() << endl;
        return 0;
    }
    else if(c == 'R'){//みんながRをとる時
        cout << fr(s,false).val() << endl;
    }
    else if(c == 'L'){ //みんながLをとる時
        cout << fl(s,false).val() << endl;
    }
    return 0;
}