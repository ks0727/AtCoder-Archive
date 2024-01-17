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
    ll nc = n;
    int digit = 0;
    while(nc > 9){
        nc /= 10;
        digit++;
    }
    digit++;
    string a = "02468";
    string b = "2468";
    ll ans = 0;
    if(digit == 1) ans = 0;
    else if(digit == 2) ans = 5;
    else{
        ans = 4;
        rep(i,digit-2) ans*=5;
    }
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
        return idx;
    };
    string s = "";
    int size = digit;
    rep(i,size){
        if(i == 0){
            s += b[f(ans,digit,b)];
            ans -= pow(5,digit-1)*f(ans,digit,b);
            digit--;
        }else{
            s += a[f(ans,digit,a)];
            ans -= pow(5,digit-1)*f(ans,digit,b);
            digit--;
        }
    }
    cout << s << endl;
    return 0;
}