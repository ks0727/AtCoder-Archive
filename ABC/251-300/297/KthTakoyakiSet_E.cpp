/*
問題文
AtCoder 王国では、N 種類のたこ焼きが売られています。i 種類目のたこ焼きの値段は Ai円です。
高橋君は、合計で 1 個以上のたこ焼きを買います。このとき、同じたこ焼きを複数個買うことも許されます。
高橋君が支払う金額としてあり得るもののうち、安い方から K 番目の金額を求めてください。
ただし、同じ金額を支払う方法が複数存在する場合は 
1 回だけ数えます。
*/

/*以下公式の解説*/
#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    set<ll> st;
    auto push = [&](ll x){ /*ラムダ式をもちいた関数の書き方*/
        rep(i,n) {
            ll nx = x + a[i]; /*nxにはxにa[i]の値段を足したものを入れていく*/
            st.insert(nx); /*集合の要素にそれを追加する*/
        }
    };
    push(0);

    rep(i,k-1){
        ll x = *st.begin();
        st.erase(x);
        push(x);
    }
    ll ans = *st.begin();
    cout << ans << endl;
    return 0;
}

