#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n; ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    int sum = 0;
    set<int> em,ap;
    rep(i,n){
        if(a[i] == 0) em.insert(i);
        else{
            ap.insert(i);
            sum++;
        }
    }
    auto f = [&](auto f,int num,ll rest)->void{
        ll n_rest = rest % num;
        ll now = rest / num;
        for(int i : ap){
            if(a[i] >= now){
                a[i] -= now;
                if(rest >= now) rest -= now;
                else{
                    if(n_rest+rest >= now){
                        n_rest = n_rest + rest - now;
                        rest = 0;
                    }else return;
                }
            }else{
                ap.erase(i);
                em.insert(i);
                if(rest >= a[i]){
                    rest -= a[i];
                }else{
                    if(n_rest+rest >= a[i]){
                        n_rest = n_rest+rest-a[i];
                        rest = 0;
                    }else return;
                }
                n_rest += now - a[i];
                a[i] = 0;
            }
            if(rest + n_rest <= 0) return;
        }
        return f(f,ap.size(),rest+n_rest);
    };
    f(f,sum,k);
    for(int x : a) cout << x << ' ';
    cout << endl;
    return 0;
}