#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

const int INF = 1001001001;
struct P{
    int val,num; //val:値　num:個数
    P(int val=0,int num=0):val(val),num(num){}
};
struct S{ //Sは(一番目に大きい数、その個数、二番目に大きい数、その個数)を保存している
    P a, b; //aが最大値の情報,bが二番目に大きい数の情報
    S(P a=P(), P b=P()):a(a),b(b){}
};
S _op(S x, P p){
    if(p.val == x.b.val){ //もしpの値とxの二番目に大きい数が同じなら
        x.b.num += p.num; //xの二番目に大きい数の個数にpの数をたす
        return x;
    }
    if(p.val == x.a.val){//もしpの値とxの最大値が同じなら
        x.a.num += p.num;
        return x;
    }
    if(p.val < x.b.val) return x; //もしpの値がxの二番目に大きい値より小さいなら何もしない
    x.b = p; //それ以外の場合、xの二番目に大きい数はpになる
    if(x.a.val < x.b.val) swap(x.a,x.b); //もしもxの最大値と二番目に大きい数が入れ替わっていたら、それをswap
    return x;
}
S op(S x, S y){
    return _op(_op(x,y.a),y.b); //2つの情報に対して、まずxとyの最大値でやった後に、その後の情報とyの二番目に大きい数でやる
}
S e(){
    return S(P(-INF-1,0),P(-INF,0)); //とても小さい数が0個入っているとすれば計算に何の影響も及ぼさない
}
int main(){
    int n,q;
    cin >> n >> q;
    segtree<S,op,e> t(n);
    rep(i,n){
        int a;
        cin >> a;   
        t.set(i,S(P(a,1),P(-INF,0)));
    }
    rep(qi,q){
        int type;
        cin >> type;
        if(type == 1){
            int p,x;
            cin >> p >> x;
            p--;
            t.set(p,S(P(x,1),P(-INF,0)));
        }else{
            int l,r;
            cin >> l >> r;
            l--;
            S s = t.prod(l,r);
            int ans = s.b.num;
            cout << ans << '\n';
        }
    }
    return 0;
}