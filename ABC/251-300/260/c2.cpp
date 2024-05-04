#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll n,x,y;
    cin >> n >> x >> y;
    auto f = [&](auto f,int level,bool isred)->ll{
        if(level == 1 && isred) return 0;
        if(level == 1 && !isred) return 1;
        ll res = 0;
        if(isred){
            res = f(f,level-1,true) + x * f(f,level,false);
        }else{
            res = f(f,level-1,true) + y*f(f,level-1,false);
        }
        return res;
    };
    ll ans = f(f,n,true);
    cout << ans << endl;
    return 0;
}