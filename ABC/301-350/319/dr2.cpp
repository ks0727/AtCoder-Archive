#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i =0;i<(n);i++)
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> l(n);
    rep(i,n) cin >> l[i];
    ll left = 0,right = 1e15;
    while(right - left > 1){
        ll w = (left+right)/2;
        int lines = 0;
        ll rest = 0;
        bool ok = true;
        rep(i,n){
            if(rest >= l[i]+1){
                rest -= (l[i]+1);
            }else{
                rest = w - l[i];
                lines++;
                if(rest < 0){
                    ok = false;
                    break;
                }
            }
        }
        if(!ok){
            left = w;
            continue;
        }
        if(lines <= m){
            right = w;
        }else{
            left = w;
        }
    }
    cout << right << endl;
    return 0;
}