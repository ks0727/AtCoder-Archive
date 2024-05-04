#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int a,b; ll c;
    cin >> a >> b >> c;
    int pc = __builtin_popcountll(c);
    int d = a+b-pc;
    if(d%2 != 0 || d < 0){
        cout << -1 << endl;
        return 0;
    }
    d = max(0,d/2);
    int x_pop = a - d;
    int y_pop = b - d;
    if(x_pop < 0 || y_pop < 0){
        cout << -1 << endl;
        return 0;
    }
    auto tobi = [&](ll x){
        string res = "";
        while(x > 0){
            res += x%2+'0';
            x /=2;
        }
        reverse(res.begin(),res.end());
        return res;
    };
    auto btoll = [&](string s){
        ll res = 0;
        rep(i,s.size()){
            if(s[i] == '1'){
                res = res*2+1;
            }else{
                res = res*2;
            }
        }
        return res;
    };
    string sx = "";
    string sy = "";
    bitset<60> cbit(c);
    rep(i,60){
        if(cbit[i] == 1){
            if(x_pop > 0){
                x_pop--;
                sx += '1';
                sy += '0';
            }else if(y_pop > 0){
                y_pop--;
                sy += '1';
                sx += '0';
            }
        }else{
            if(d > 0){
                d--;
                sx += '1';
                sy += '1';
            }else{
                sx += '0';
                sy += '0';
            }
        }
    }
    if(x_pop != 0 || y_pop != 0 || d != 0){
        cout << -1 << endl;
        return 0;
    }
    reverse(sx.begin(),sx.end());
    reverse(sy.begin(),sy.end());
    ll x = btoll(sx);
    ll y = btoll(sy);
    //cout << cbit <<endl;
    //cout << sx << endl;
    //cout << sy << endl;
    cout << x << ' ' << y << endl;
    return 0;
}