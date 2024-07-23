#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

ll pow(int a,int b){
    ll res = 1;
    rep(i,b) res *= a;
    return res;
}

int main(){
    ll n;
    cin >> n;
    int digit = 0;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    n--;
    digit++;
    while(true){
        int k = (digit+1)/2-1;
        ll val = pow(10,k)*9;
        if(n > val) n -= val;
        else break;
        digit++;
    }
    int k = (digit+1)/2-1;
    ll val = pow(10,k);
    n += val-1;
    string s = to_string(n);
    string t = s;
    if(digit%2 == 1) s.pop_back();
    reverse(t.begin(),t.end());
    string ans = s + t;
    cout << ans << endl;
    return 0;
}