#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll pow(ll a,int b){
    ll res = 1;
    rep(i,b) res *= a;
    return res;
}
int main(){
    ll n;
    cin >> n;
    string a = "02468";
    string b = "2468";
    auto f = [&](ll res,int digit,string s){
        ll now = 0;
        int idx = 0;
        rep(i,s.size()){
            now += pow(5,digit-1);
            if(now >= res){
                idx = i-1;
                break;
            }
        }
        if(idx < 0) idx = 0;
        return idx;
    };
    ll nc = n;
    vector<ll> d;
    ll now = 5;
    rep(i,20){
        if(i == 1) now *= 4;
        else if(i > 1) now *= 5;
        d.push_back(now);
    }
    int digit = 0;
    rep(i,20){
        if(n <= d[i]){
            digit = i+1;
            break;  
        }
    }
    string ans = "";
    int i = 0;
    while(n > 5){
        if(i == 0){
            ans += b[f(n,digit,b)];
            n -= pow(5,digit-1);
            cout << pow(5,digit-1) << endl;
            digit--;
        }else{
            ans += a[f(n,digit,a)];
            n -= pow(5,digit-1);
            digit--;
        }
        i++;
    }
    ans += a[n];
    cout << ans << endl;
    return 0;
}