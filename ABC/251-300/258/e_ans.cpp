#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll n,q ,x;
    cin >> n >> q >> x;
    vector<ll> w(n);
    rep(i,n) cin >> w[i];
    ll s = 0;
    rep(i,n) s += w[i];
    ll rd = x/s; //何周するか
    ll rem = x%s; //そのあまり
    
    //iから始めて何個のじゃがいもを詰められるかを持っておく
    vector<ll> a(n);
    ll na = rd*n;
    rep(i,n){
        while(rem >= 1){
            rem -= w[(i+na)%n];
            na++;
        }
        a[i] = na;
        rem += w[i];
        na--;
    }

    //ダブリング
    const int D = 41;
    vector d(D,vector<int>(D)); //二次元配列 2^0~2^39先を見るグラフを作成する(つまりn頂点のグラフを40個作成)
    rep(i,n) d[0][i] = (i+a[i])%n;
    rep(i,D-1)rep(j,n){
        d[i+1][j] = d[i][d[i][j]];
    }

    rep(qi,q){
        ll k;
        cin >> k;
        k--;
        int si = 0;
        for(int i=D-1;i>=0;i--){
            if(k&1<<i){
                si = d[i][si];
            }
        }
        cout << a[si] << endl;
    }
    return 0;
}