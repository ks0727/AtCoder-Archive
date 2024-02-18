#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll h,w; int n;
    cin >> h >> w >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.rbegin(),a.rend());
    vector<ll> ts(26);
    auto f = [&](auto f, ll h, ll w)->void{
        if(h == 0 || w == 0) return;
        ll bigger = max(h,w);
        ll smaller = min(h,w);
        //今できる最も大きなサイズを求める
        int size = 0;
        rep(i,26){
            if((1<<i) > smaller) break;
            size = i;
        }
        ts[size] += bigger/(1<<size);
        ll x = (1<<size);
        if(bigger == h){ //もしhの方が大きかった時
            f(f,x*(h/x),w-x);
            f(f,h-x*(h/x),w);
        }else{ //wの方が大きかった時
            f(f,h-x,x*(w/x));
            f(f,h,w-x*(w/x));
        }
    };
    f(f,h,w); //各サイズが何個ずつ作れるのかをもつ
    //for(int x : ts) cout << x << ' '; cout << endl;
    bool ans = true;
    rep(i,n){ //a[i]は今作る必要のある最大のサイズ
        for(int j=25;j>=1;j--){ //今最大よりも大きいサイズを作ることができる場合は両替しておく
            if(j > a[i] && ts[j] > 0){
                ts[j-1] += ts[j]*4;
                ts[j] = 0;
            }
        }
        if(ts[a[i]] > 0){
            ts[a[i]]--;
        }else ans = false;
    }
    //for(int x : ts) cout << x << ' '; cout << endl;
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}