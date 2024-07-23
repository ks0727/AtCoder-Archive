#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    ll n;
    cin >> n;
    const int M = 38;
    vector<ll> arr(M);
    vector<ll> s(M+1);
    arr[0] = 9;
    arr[1] = 9;
    rep(i,M){
        if(i <= 1) continue;
        arr[i] = 9 * (arr[i-2]+1);
    }
    arr[0] = 10;
    rep(i,M+1) s[i+1] = s[i]+arr[i];
    int digit = 0;
    rep(i,M){
        if(s[i] >= n){
            digit = i;
            break;
        } 
    }
    if(digit == 1){ //1桁の時の処理
        cout << n-1 << endl;
        return 0;
    }
    ll ord = n - s[digit-1];
    string ans = "";
    while(digit >= 2){
        cout << ord << endl;
        ll num_per_one = s[digit-2];
        ll h = (ord+num_per_one-1)/num_per_one;
        char add = h + '0';
        ord -= num_per_one*h;
        ans += add;
        digit-=2;
    }
    string nt = ans;
    reverse(nt.begin(),nt.end());
    char mid = ord+'0';
    ans += mid;
    ans += nt;
    cout << ans << endl;
    return 0;
}