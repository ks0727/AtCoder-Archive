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
    rep(i,n) cin >> p[i];
    string s;
    cin >> s;
    string sl,sr;
    sl = sr = s;
    sl.insert(sl.begin(),'L');
    sr.insert(sr.begin(),'R');
    auto f = [&](string& ns)->mint{
        vector<bool> used(n+1);
        mint res = 1;
        if(ns[0] == 'L'){ //みんなが左をとるとき
            used[0] = true;
            rep(i,n){
                int right = (p[i]+1)%(n+1);
                if(used[p[i]]) return 0; //左が使われていたらだめ
                if(ns[p[i]] == 'R' && !used[right]) return 0; //聞き手が右でかつ右が空いていたらだめ
                if(ns[p[i]] == 'R' && used[right]) used[p[i]] = true; //聞き手が右で右が使われていたら左を使う
                if(ns[p[i]] == 'L') used[p[i]] = true; //聞き手が左だったら左を使う
                if(ns[p[i]] == '?'){
                    if(!used[p[i]] && !used[right]){
                        used[p[i]] = true;
                    } 
                    if(used[right]){
                        res *= 2;
                        used[p[i]] = true;
                    }
                }
            }
        }else{ //みんなが右をとる時
            used[1] = true;
            rep(i,n){
                int right = (p[i]+1)%(n+1);
                if(used[right]) return 0;
                //以下右は使われていない
                if(ns[p[i]] == 'L' && !used[p[i]]){} return 0; //左ききで左が使われていない時だめ
                if(ns[p[i]] == 'L' && used[p[i]]) used[right] = true; //左ききで左が使われているときは左を使う
                if(ns[p[i]] == 'R') used[right] = true; //右利きの時は右を使う
                if(ns[p[i]] == '?'){
                    if(!used[p[i]]) used[right] = true; //右も左も使われていない時、右を使う
                    if(used[p[i]]){
                        used[right] = true; //左が使われている時とき右を使って答えは2倍になる
                        res *= 2;
                    }
                }
            }
        }
        return res;
    }; 
    cout << f(sl).val() << endl;
    cout << f(sr).val() << endl;
    mint ans = f(sl)+f(sr);
    cout << ans.val() << endl;
    return 0;
}