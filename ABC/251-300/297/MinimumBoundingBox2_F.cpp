/*
縦 H 行、横 W 列のグリッドがあります。
このグリッドから一様ランダムに K 個のマスを選びます。
選んだマスを全て 含むような（グリッドの軸に辺が平行な）最小の長方形に含まれるマスの個数がスコアとなります。
得られるスコアの期待値を mod 998244353 で求めてください。
*/
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0;i< (n); i++)

// auto mod int
const int mod = 998244353;
struct mint {
  ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
    }
    mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
    }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
    }

  // for prime mod
    mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

// combination mod prime
// https://youtu.be/8uowVvQ_-Mo?t=6002
// https://youtu.be/Tgd_zLfRZOQ?t=9928
struct modinv {
    int n; vector<mint> d;
    modinv(): n(2), d({0,1}) {}
    mint operator()(int i) {
        while (n <= i) d.push_back(-d[mint::mod()%n]*(mint::mod()/n)), ++n;
        return d[i];
    }
    mint operator[](int i) const { return d[i];}
    } invs;
    struct modfact {
    int n; vector<mint> d;
    modfact(): n(2), d({1,1}) {}
    mint operator()(int i) {
        while (n <= i) d.push_back(d.back()*n), ++n;
        return d[i];
    }
    mint operator[](int i) const { return d[i];}
    } facts;
    struct modfactinv {
    int n; vector<mint> d;
    modfactinv(): n(2), d({1,1}) {}
    mint operator()(int i) {
        while (n <= i) d.push_back(d.back()*invs(n)), ++n;
        return d[i];
    }
    mint operator[](int i) const { return d[i];}
    } ifacts;
    mint comb(int n, int k) {
    if (n < k || k < 0) return 0;
    return facts(n)*ifacts(k)*ifacts(n-k);
    }

int main(){
    int h,w,k;
    cin >> h >> w >> k;
    mint ans;
    for(int r = 1;r <= h; r ++){
        for(int c = 1; c <=w; c ++){
            mint now;
            rep(s,1<<4){
                int nr =r, nc = c;
                if(s&1) nr--;
                if(s&2) nr--;
                if(s&4) nc--;
                if(s&8) nc--;
                if(nc <0 || nc < 0) continue;
                int sg = (__builtin_parity(s)) ? -1 : 1;
                now += comb(nr*nc,k)*sg;
            }
            ans += now * r * c (h-r+1)*(w-c+1);
        }
    }
    ans /= comb(h*w,k);
    cout << ans.val() << endl;
    return 0;
}
